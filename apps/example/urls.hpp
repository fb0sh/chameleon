#include "../../chameleon/urls.h"
#include "views.hpp"

namespace example{
    
    void init_urls(){
        path("/test_example/<id>",(void *)test_example);
    }

};