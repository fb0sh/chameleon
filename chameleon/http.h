#ifndef CHAMELEON_HTTP
#define CHAMELEON_HTTP

#include <regex>
#include <map>
#include <sstream>

#include <string>
using std::string;

#include "inja.hpp"

#include "logger.hpp"
extern Logger cl;
const string HTTP_SERVER = "Chameleon. by Freet/1.0";
const string HTTP_VERSION = "HTTP/1.1";
const string HTTP_DELIM = "\r\n";
extern std::regex http_url_rp;

class HttpServer {
public:
    int Run(const char *ip, unsigned int port, int max_clients = 1024);
private:
    void Reciver(int server);
};

class HttpRequest{
public:
    int fd, port;
    string ip;

    string method, path, version, all;
    std::map<string, string> headers, path_data;

    char *body;
    size_t body_len = 0;

public:
    template<typename T>
    T attain(string name){
        T ans;
        std::stringstream ss;
        if(this->path_data.count(name))  ss << this->path_data[name];
        else ss << "";
        ss >> ans;
        return ans;
    }// request.attain<int>("name")
    HttpRequest(int fd, string ip, unsigned int port);

    void Close();
    HttpRequest();
    ~HttpRequest();
};
void NewHttpRequest(int fd, string ip, unsigned int port);

class HttpResponse{
public:
    HttpRequest *request;
    string status_code = "200";
    std::map<string, string> headers= {{"Server",HTTP_SERVER},{"Content-Type", "text/html"}};

public:
    void Fire(const char *content, ssize_t len);
    HttpResponse(HttpRequest *request);
    HttpResponse();
    ~HttpResponse();

};

void NewHttpResponse(HttpRequest *request, string content, string status_code="200");
void NewFileResponse(HttpRequest *request, string file_path, string status_code="200");
void NewJsonResponse(HttpRequest *request, string data, string status_code="200");
void NewJsonResponse(HttpRequest *request, inja::json data, string status_code="200");
void Render(HttpRequest *request, string html_path, inja::json data, string status_code="200");

#endif
