#include "observer.h"

void TimeObserver::update(std::string& lineCommand){
    if(lineCommand == "{"){
        startBulk();
    }
    else if(lineCommand == "}"){
        bulk();
    }
    else{
        bulkBlock.push_back(lineCommand);
    }

};

void TimeObserver::startBulk(){
    bulkBegin = boost::lexical_cast<std::string>(time(nullptr));
};

void TimeObserver::bulk(){
    auto fileName = bulkBegin.append(".log");
    std::cout<<bulkBegin<<std::endl;
    std::ofstream bulkFile(fileName);
    for(auto i : bulkBlock){
        bulkFile<<i;
        std::cout<<i<<" ";
    }
    std::cout<<bulkBegin<<'\n';
    bulkBlock.clear();
};
