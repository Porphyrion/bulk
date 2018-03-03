#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <vector>
#include "observer.h"



class CommandLine{
public:
    void notify(){
        for(auto i : subs){
            i->update(nowLine);
        }
    }

    void subscribe(Observer *obs) {
        subs.push_back(obs);
    }

    void setCommnand(std::string& line){
        nowLine = line;
        notify();
    }

private:
    std::vector<Observer *> subs;
    std::string nowLine;
};



#endif
