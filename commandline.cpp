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

void bulk::CommandLine::Commnand(std::string& line){

    if(line == "{"){
        dynamic_counter++;
        if(dynamic_counter == 1){
            commandBlock.clear();
            dynamic = true;
            setStatus(start);
        }
    }
    else if(line == "}"){
        dynamic_counter--;
        if(!dynamic_counter){
            dynamic = false;
            setStatus(stop);
        }
    }
    else{
        commandBlock.push_back(line);
        if(!dynamic){
            if(commandBlock.size() == 1){
                setStatus(start);
            }
            else if(commandBlock.size() == N){
                setStatus(stop);
            }
        }
    }
};

void bulk::CommandLine::setStatus(int s){
    status = s;

    if(status == LAST_BULK){
        if(dynamic) return;
        else status = STOP;

    }
    notify();
}
