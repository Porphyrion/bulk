#include "bulk.h"

void bulk::CoutObserver::update(int s){
    if(s == STOP){
        std::cout<<std::endl<<"bulk: ";
        for(auto i : cb->commands){
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
    }
};

