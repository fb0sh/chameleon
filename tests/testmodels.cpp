#include "../chameleon/models.hpp"

#include <string>
#include <iostream>

class Tm: public Model{
public:
    int id;
    std::string name;
    template<class Archive>
    void hibernate(Archive &ar){
        ar & HIBERLITE_NVP(id);
        ar & HIBERLITE_NVP(name);
    }
    json toJsonObj(){
        return { {"id",this->id},{"name", this->name} };
    }
};
HIBERLITE_EXPORT_CLASS(Tm)


int main(){
    db.open("test.sqlite3");
    db.registerBeanClass<Tm>();

    for(auto s: db.checkModel()){
        std::cout << s << std::endl;
    }
    db.createModel();
    auto p = db.createBean<Tm>();
    p->id = 123;
    p->name = "bash";
    std::cout << p->toJsonStr() << std::endl;
    db.close();
    return 0;
}