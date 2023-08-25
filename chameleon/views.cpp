#include "http.h"
#include "views.h"

void chameleon(HttpRequest *request) {
	return NewHttpResponse(request,"<html><body style='margin:10%;'><div><center><h1 style ='text-decoration:underline;'>Welcome to "+HTTP_SERVER+"</h1></center></div></body></html>");
}

void notfound(HttpRequest *request) {
	return NewFileResponse(request, "template/404.html", "400");
}

void handle_static(HttpRequest *request) {
	if(request->path_data.count("any")){
		string file_path = request->path_data["any"];
		if(file_path != "") return NewFileResponse(request,"static/"+file_path);
	}
	return notfound(request);
}

void testjson(HttpRequest *request){
	return NewJsonResponse(request,{{"id",1},{"name","test"}});
}
void testrender(HttpRequest *request){
	return Render(request,"template/test.html",{{"name","test"}});
}