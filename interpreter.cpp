#include "bulk.h"

void bulk::Interpreter::readCommand(std::string &command){
    if(command == "{"){
        if(!dynamic_counter)
            cb->setStatus(Status::start_dynamic);
        dynamic_counter++;
    }
    else if(command == "}"){
        dynamic_counter--;
        if(!dynamic_counter)
            cb->setStatus(Status::stop);
    }
    else{
        cb->appendCommnad(command);
    }
};

void bulk::LogObserver::update(Status s){
    if(s == Status::start){
        bulkBeginTime = boost::lexical_cast<std::string>(time(nullptr));
        bulkFileName = bulkBeginTime;
        bulkFileName.append(".log");
    }
    else if(s == Status::stop){
        std::ofstream bulkFile(bulkFileName, std::ios::out | std::ios::app);
        bulkFile<<"bulk: ";
        for(auto i : cb->commands){
            bulkFile<<i<<" ";
        }
        bulkFile<<std::endl;
        bulkFile.close();
    }
};
