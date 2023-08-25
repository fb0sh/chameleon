
#include "urls.h"
#include <regex>
using std::smatch;
using std::regex_match;


map<string, void *> patterns = {
	{"/chameleon",(void *)chameleon},
	{"/notfound",(void *)notfound},
	{"/testjson", (void *)testjson},
	{"/testrender", (void *)testrender},
	{"/static/<any>",(void *)handle_static}
};

vector<URL_MODE> __patterns__;

void __handle__patterns__() {
	for(auto mode : patterns) {
		URL_MODE temp;
		string t_str;
		temp.origin = mode.first;
		temp.f = mode.second;
		int flag = 0;
		for(int i = 0; i < mode.first.length(); ++i) {
			if(mode.first.at(i) == '<') {
				if(flag){
					cl.fatal(mode.first + " was error!");
					exit(EXIT_FAILURE);
				}
				flag = 1;
				string arg;

				int j = i + 1;
				for(; j < mode.first.length(); ++j) {
					if(mode.first.at(j) == '>') break;
					else {
						arg += mode.first.at(j);
					}
				}
				i = j;// ++i
				temp.args.push_back(arg);
				t_str += "(.*?)";
				flag = 0;
			} else {
				t_str += mode.first.at(i);
			}
		}
		temp.rp = regex(t_str);
		__patterns__.push_back(temp);
	}
}

string contain(HttpRequest &request) {
	/* find the mode
	*/
	smatch result;
	for(auto mode : __patterns__) {
		if(regex_match(request.path, result, mode.rp)) {
			for(int i = 0; i < mode.args.size(); ++i) {
				request.path_data.insert({ mode.args[i], result.str(i + 1) });
				// result.str(0) is full match
			}
			return mode.origin;
		}
	}
	return "/notfound";
}

void matcher(HttpRequest &request) {
	// match and execute
	string mode = contain(request);
	cl.debug("The HttpRequest- " + request.path + " was matched " + mode);
	void *f = patterns[mode];
	((void (*)(HttpRequest &))f)(request);
}

void path(const char *url_mode, void *f) {
	/* use to insert into the patterns 
	*/
	patterns.insert({ url_mode,f });
}

void url(const char *regex_mode, void *f){
	// endure
}

