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
