#include "init.hpp"

int main(int argc, char *argv[]){
    cl.setDebug(0);
    __init_dbs__();
    __init_urls__();
    return (new HttpServer)->Run("0.0.0.0",3147);
}