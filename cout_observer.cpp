#include "bulk.h"

void bulk::CoutObserver::update(int s){
    if(s == stop){
        std::cout<<"bulk: ";
        for(auto i : cm->commandBlock){
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
    }
};

/*void bulk::CoutObserver::bulk(){
    auto fileName = bulkBegin.append(".log");
    std::cout<<bulkBegin<<std::endl;
    std::ofstream bulkFile(fileName);
    for(auto i : bulkBlock){
        bulkFile<<i;
        std::cout<<i<<" ";
    }
    std::cout<<bulkBegin<<'\n';
    bulkBlock.clear();
};*/
