#include "../../chameleon/models.hpp"

class exampleModel:public Model {
public:
    int id;
    template<class Archive>
    void hibernate(Archive &ar){
        ar & HIBERLITE_NVP(id);
    }
    json toJsonObj(){
        return { {"id",this->id} };
    }
    
};