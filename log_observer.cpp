#include "bulk.h"

void bulk::LogObserver::update(int s){
    if(s == start){
        bulkBeginTime = boost::lexical_cast<std::string>(time(nullptr));
        bulkBeginTime.append(".log");
    }
    else if(s == stop){
        std::ofstream bulkFile(bulkBeginTime);
        bulkFile
        for(auto i : cm->commandBlock){
            bulkFile<<i<<" ";
        }
    }
    else if(s == dynamic_start){
        bulkBeginTime.clear();
    }
};
