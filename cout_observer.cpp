#include "bulk.h"

void bulk::CoutObserver::update(int s){
    if(s == STOP){
        std::cout<<"bulk: ";
        for(auto i : cm->commandBlock){
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
    }
};
