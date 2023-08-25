#include "../../chameleon/views.h"
#include "models.hpp"

void test_example(HttpRequest *request) {
	int id = request->attain<int>("id");
	string final_text;
	try {
		auto c = db.createBean<exampleModel>();
		c->id = id;
		final_text = c->toJsonStr();
	} catch(const std::exception &e) {
		final_text = e.what();
	}
	
	NewHttpResponse(request, final_text);
}