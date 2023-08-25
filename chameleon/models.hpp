#ifndef CHAMELEON_MODELS
#define CHAMELEON_MODELS
#include "inja.hpp"
using inja::json;

#include "hiberlite/hiberlite.h"
static hiberlite::Database db;
// golbal db

class Model {
	//friend class hiberlite::access;
public:
	virtual json toJsonObj() = 0;
	std::string toJsonStr() {
		json data = this->toJsonObj();
		return data.dump();
	}
	/*
		string toJson(){
			json data;
			data["name"]=this->bash;

			return data;
		}
	
	*/
};

#endif // !CHAMELEON_MODELS
