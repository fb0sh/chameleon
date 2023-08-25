#include "../chameleon/http.h"


int main(){
    cl.setDebug(0);

    return (new HttpServer)->Run("0.0.0.0",3147);
}