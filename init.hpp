// include each app urls
#include "apps/example/urls.hpp"

const string project_name = "temp";

HIBERLITE_EXPORT_CLASS(exampleModel)

void __init_dbs__(){
    db.open(project_name+".sqlite3");
	// register each app model
    {
        db.registerBeanClass<exampleModel>();

    }
	for(string m : db.checkModel()) cout << m << endl;
    try { db.createModel(); } catch(const std::exception &e) {}
}


void __init_urls__(){
        cl.setDebug(0);
	// init each app urls
    example::init_urls();

}


