#include "bulk.h"

void bulk::CoutObserver::update(Status s){
    if(s == Status::stop){
        std::cout<<"bulk: ";
        for(auto i : cb->commands){
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
    }
};
