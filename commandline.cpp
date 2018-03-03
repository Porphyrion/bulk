#include "commadline.h"
#include <string>

void bulk::CommandLine::notify(){
    for(auto i : subs){
        i->update(nowLine);
    }
};

void bulk::CommandLine::subscribe(Observer *obs){
        subs.push_back(obs);
};

void bulk::CommandLine::setCommnand(){
    nowLine = line;
    notify();
};
