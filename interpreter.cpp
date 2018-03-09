#include "bulk.h"

void bulk::Interpreter::readCommand(std::string &command){
    if(command == "{"){
        if(!dynamic_counter)
            cb->setStatus(START_DYNAMIC);
        dynamic_counter++;
    }
    else if(command == "}"){
        dynamic_counter--;
        if(!dynamic_counter)
            cb->setStatus(STOP);
    }
    else{
        cb->appendCommnad(command);
    }
};
