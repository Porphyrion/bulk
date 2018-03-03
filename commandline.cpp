#include "commadline.h"
#include <string>

void CommandLine::notify(){
    for(auto i : subs){
        i->update(nowLine);
    }
};

void CommandLine::subscribe(Observer *obs){
        subs.push_back(obs);
};

void CommandLine::setCommnand{
    nowLine = line;
    notify();
};
