#include "bulk.h"

void bulk::CommandBlock::notify(){
    for(auto i : subs){
        i->update(status);
    }
    if(status == STOP) {
        commands.clear();
        if(dynamic) dynamic = false;
    }
};

void bulk::CommandBlock::subscribe(Observer * obs){
        subs.push_back(obs);
};

void bulk::CommandBlock::setStatus(int s){
    status = s;
    if(status == START) commands.clear();
    else if(status == START_DYNAMIC){
        setStatus(STOP);
        dynamic = true;
        status = START;
    }
    else if(LAST_BULK){
        if(!dynamic) status = STOP;
    }
    notify();
}

void bulk::CommandBlock::appendCommnad(std::string & command){
    if(!dynamic){
        if(commands.size() == 0){
            setStatus(START);
        }
        commands.push_back(command);
        if(commands.size() == N){
            setStatus(STOP);
        }
    }
    else{
        commands.push_back(command);
    }
}
