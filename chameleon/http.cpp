#include "http.h"
#include "urls.h"
#include "httptool.hpp"

#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <string.h>
#include <thread>

Logger cl("log.txt", 1);
std::regex http_url_rp("(GET|POST|HEAD) (.*?) HTTP\\/(.*)");
// HttpRequest


HttpRequest::HttpRequest(int fd, string ip, unsigned int port){
    this->fd = fd;
    this->ip = ip;
    this->port = port;

    char c;
    while(recv(this->fd,&c,1,0) && c!= ' ') this->method += c;
    while(recv(this->fd,&c,1,0) && c!= ' ') this->path += c;
    while(recv(this->fd,&c,1,0) && c!= '\r') this->version += c;
    this->all = this->method + " " + this->path + " " + this->version + HTTP_DELIM;

    if(!regex_match(this->method + " " + this->path + " " + this->version ,http_url_rp)){
        cl.warn("This request is not a request\n"+this->all);
        // 400 bad request
        this->Close();
        return;
    }
    // GET / HTTP/1.1\r\n
    // \r\n
    // asdasd
    int flag = 1;
    while(flag){
        string first, second;
        while(recv(this->fd,&c,1,0)){
            if(c=='\n'){
                this->all+=c;
                recv(this->fd,&c,1,0);
                if(c=='\r'){
                    this->all+=c;
                    recv(this->fd,&c,1,0);
                    if(c=='\n'){
                        this->all+=c;
                        flag=0;
                        goto HTTP_CONTENT;
                    }
                }
            }

            if(c != ':'){
                first+=c;
                this->all+=c;
            }else break;
        }

        this->all+=c; // :
        recv(this->fd,&c,1,0);// space
        this->all+=c; // space

        while(recv(this->fd,&c,1,0) && c != '\r') {
            this->all+=c;
            second += c;
        }
        this->all+=c;// \r
        this->headers.insert({ first,second });
    }

HTTP_CONTENT:
    if(this->method == "POST" && this->headers.count("Content-Length")) {
        long int len = atol(this->headers["Content-Length"].c_str());
        this->body = (char *)malloc(sizeof(char) * len);
        memset(this->body, 0, len);
        recv(this->fd,this->body,len,0);
        this->all += this->body;
    }

}// end HttpRequest

void HttpRequest::Close(){
    close(this->fd);
    if(this->body_len!=0) free(this->body);
}

HttpRequest::HttpRequest(){}
HttpRequest::~HttpRequest(){
    close(this->fd);
    if(this->body_len!=0) free(this->body);
}

// end HttpRequest


int HttpServer::Run(const char *ip, unsigned int port, int max_clients){
    int server = socket(AF_INET, SOCK_STREAM, 0);
    if(server == -1 ){
        cl.fatal("init socket error");
        exit(server);
    }
    
    int opt = 1;
    if(int err = setsockopt(server, SOL_SOCKET,SO_REUSEADDR, (const void *)&opt, sizeof(opt))!=0){
        cl.fatal("setsockopt SO_REUSEADDR error");
        exit(err);
    }
    int timeout=6000;
    setsockopt(server,SOL_SOCKET, SO_RCVTIMEO,(const char *)&timeout,sizeof(timeout));


    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr=inet_addr(ip);
    int server_addr_len = sizeof(server_addr);
    if(int err = bind(server,(sockaddr *)&server_addr,server_addr_len) != 0){
        cl.fatal("bind ip port error");
        exit(err);
    }

    if(int err = listen(server,max_clients) != 0 ){
        cl.fatal("listen error");
        exit(err);
    }

    // __handle__patterns__();
    cl.debug("Init urls");
    __handle__patterns__();
    for(auto u: __patterns__){
        cl.debug(u.origin);
    }

    cl.info("HttpServer init on http://"+string(ip)+":"+to_string(port));

    this->Reciver(server);

    return close(server);
}

void HttpServer::Reciver(int server){
    for(;;){
        sockaddr_in client_addr;
        socklen_t client_addr_len;
        int client = accept(server,(sockaddr *)&client_addr,&client_addr_len);

        char *ip = inet_ntoa(client_addr.sin_addr);
        unsigned int port = ntohs(client_addr.sin_port);

        if(client!=-1){

            std::thread temp(NewHttpRequest,client,ip,port);
            temp.detach();

        }else cl.error("A Request from "+string(ip)+":"+to_string(port)+" connect error!");
    }
}


void NewHttpRequest(int fd, string ip, unsigned int port){
    cl.debug("HttpRequest from "+string(ip)+":"+to_string(port));
    HttpRequest req(fd, ip , port);
    matcher(req);
    // matcher
}

void HttpResponse::Fire(const char *content, ssize_t len){
    // Content-Length
    // Date
    this->headers["Content-Length"]=to_string(len);
    this->headers["Date"]=gmt_time();
    

    string header = HTTP_VERSION + " " + this->status_code + " " + GetHttpCode(this->status_code) + HTTP_DELIM;
    for(auto each: this->headers){
        header += each.first + ": " +each.second + HTTP_DELIM;
    }
    header += HTTP_DELIM;
    
    send(this->request->fd, header.c_str(),header.length(),0);

    if(this->request->method != "HEAD"){
        if(len){
            send(this->request->fd, content, len, 0);
        }
    }

    this->request->Close();
    string all = " " + this->request->method + "\t[" +this->request->ip + ":" + to_string(this->request->port) + "]\t|" + this->headers["Content-Type"] + "|\t<" + this->status_code + ">(" + this->request->path + ")";
	cl.info(all);
}

HttpResponse::HttpResponse(HttpRequest *request){ this->request = request;}
HttpResponse::HttpResponse(){}
HttpResponse::~HttpResponse(){}

void NewHttpResponse(HttpRequest *request, string content, string status_code){
    HttpResponse r(request);
    r.status_code = status_code;
    r.Fire(content.c_str(),content.length());
}

void NewFileResponse(HttpRequest *request, string file_path, string status_code){
    // == 0 file exist
    if(access(file_path.c_str(), F_OK) != 0 ) return notfound(request);

    // filesize
    struct stat sbuf;
    stat(file_path.c_str(),&sbuf);
    ssize_t filesize = sbuf.st_size;

    // last modified
    time_t m = sbuf.st_mtime;
    tm *gmt = gmtime(&m);
    const char *fmt = "%a, %d %b %Y %H:%M:%S GMT";
    char tstr[30];
    strftime(tstr, sizeof(tstr), fmt, gmt);

    
    if(request->headers.count("If-Modified-Since")){
        if(request->headers["If-Modified-Since"]==tstr) return NewHttpResponse(request,"","304");
    }

    // suffix
    string suffix = "bin";
    for(int i = 0; i < file_path.length(); ++i) {
		if(file_path.at(i) == '.') {
			suffix = "";
			for(int j = i + 1; j < file_path.length(); ++j) {
				suffix += file_path.at(j);
			}
			break;
		}
	}
    
    HttpResponse r(request);
    r.status_code = status_code;
    r.headers["Content-Type"]   = GetMimeType(suffix);
    r.headers["Last-Modified"]  = tstr; 
    if(request->method == "HEAD") return r.Fire("",filesize);

    FILE *f = fopen(file_path.c_str(),"rb");
    char *data =(char *)malloc(sizeof(char)*filesize);
    fread(data,1,filesize,f);

    r.Fire(data,filesize);
    fclose(f);
}

void NewJsonResponse(HttpRequest *request, string data, string status_code){
    HttpResponse r(request);
    r.status_code = status_code;
    r.headers["Content-Type"]=GetMimeType("json");
    r.Fire(data.c_str(),data.length());
}

void NewJsonResponse(HttpRequest *request, inja::json data, string status_code){
    NewJsonResponse(request,data.dump(), status_code);
}

void Render(HttpRequest *request, string html_path, inja::json data, string status_code){
    inja::Environment env;
    try {
        string final_html = env.render_file(html_path, data);
        NewHttpResponse(request, final_html,status_code);
    } catch (const std::exception &e){
        NewHttpResponse(request,e.what(),"500");
    }
}