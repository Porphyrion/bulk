#include "bulk.h"

void bulk::LogObserver::update(int s){
    if(s == START){
        bulkBeginTime = boost::lexical_cast<std::string>(time(nullptr));
        bulkFileName = bulkBeginTime;
        bulkFileName.append(".log");
    }
    else if(s == STOP){
        std::ofstream bulkFile(bulkFileName, std::ios::out | std::ios::app);
        bulkFile<<"bulk: ";
        for(auto i : cb->commands){
            bulkFile<<i<<" ";
        }
        bulkFile<<std::endl;
        bulkFile.close();
    }
};
