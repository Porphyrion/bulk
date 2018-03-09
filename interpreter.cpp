#include "bulk.h"

void bulk::Interpreter::readCommand(std::string &command){
    if(command == "{"){
        if(!dynamic_counter)
            cl->setStatus(STRAT_DYNAMIC);
        dynamic_counter++;
    }
    else if(command == "}"){
        dynamic_counter--;
        if(!dynamic_counter)
            cl->setStatus(STOP);
    }
    else{
        cl->appendCommnad(command);
    }
};
