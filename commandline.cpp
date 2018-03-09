#include "bulk.h"

void bulk::CommandLine::notify(){
    for(auto i : subs){
        i->update(status);
    }
    if(status == STOP) commandBlock.clear();
};

void bulk::CommandLine::subscribe(Observer * obs){
        subs.push_back(obs);
};

void bulk::CommandLine::setStatus(int s){
    status = s;
    if(status == START) commandBlock.clear();
    if(status == STRAT_DYNAMIC){
        dynamic = true;
        status = START;
    }
    notify();
}

void bulk::CommandLine::appendCommnad(std::string & command){
    if(!dynamic){
        if(commandBlock.size() == 0){
            setStatus(START);
        }
        commandBlock.push_back(command);
        if(commandBlock.size() == N){
            setStatus(STOP);
        }
    }
    else{
        commandBlock.push_back(command);
    }


}
