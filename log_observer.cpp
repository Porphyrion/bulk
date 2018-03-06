#include "bulk.h"

void bulk::LogObserver::update(int s){
    if(s == START){
        bulkBeginTime = boost::lexical_cast<std::string>(time(nullptr));
        bulkFileName = bulkBeginTime;
        bulkFileName.append(".log");
    }
    else if(s == STOP){
        std::ofstream bulkFile(bulkFileName);
        for(auto i : cm->commandBlock){
            bulkFile<<i<<" ";
        }
    }
};
