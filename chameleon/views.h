#ifndef CHAMELEON_VIEWS
#define CHAMELEON_VIEWS

#include "http.h"

void chameleon(HttpRequest *request);
void notfound(HttpRequest *request);
void handle_static(HttpRequest *request);

void testjson(HttpRequest *request);
void testrender(HttpRequest *request);

#endif // !CHAMELEON_VIEWS
