#ifndef CHAMELEON_URLS
#define CHAMELEON_URLS

#include <string>
using std::string;
#include <map>
using std::map;
#include <vector>
using std::vector;
#include <regex>
using std::regex;


#include "views.h"

extern map<string, void *> patterns;

struct URL_MODE {
	string origin;
	regex rp;
	vector<string> args;
	void *f;
};

extern vector<URL_MODE> __patterns__;
void __handle__patterns__();
string contain(HttpRequest &request);
void matcher(HttpRequest &request);
void path(const char *url_mode, void *f);
void url(const char *regex_mode, void *f);// todo

#endif // !CHAMELEON_URLS
