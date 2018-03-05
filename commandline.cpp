#include "bulk.h"

void bulk::CommandLine::notify(){
    for(auto i : subs){
        i->update(nowCommand);
    }
};

void bulk::CommandLine::subscribe(Observer *obs){
        subs.push_back(obs);
};

void bulk::CommandLine::setCommnand(std::string& line){

    if(line == "{"){
        if(nowCommand == dynamic_work) dynamic_counter++;
        else{
            commandBlock.clear();
            nowCommand = dynamic_start;
            counter = 0;
            dynamic_counter++;
        }
    }

    else if(line == "}"){
        dynamic_counter--;
        if(dynamic_counter) {
            nowCommand = dynamic_work;
        }
        else {
            nowCommand = stop;
        }
    }
    else if(nowCommand == dont_work ){
        nowCommand = start;
        commandBlock.push_back(line);
        ++counter;
    }
    else if(nowCommand == stop){
        commandBlock.clear();
        nowCommand = start;
        ++counter;
        commandBlock.push_back(line);
    }
    else{
        if(nowCommand == dynamic_start){
            nowCommand = dynamic_work;
            commandBlock.push_back(line);
        }
        else if(nowCommand == dynamic_work){
            commandBlock.push_back(line);
        }
        else if (nowCommand == work){
            commandBlock.push_back(line);
            ++counter;
            if(counter == N){
                nowCommand = stop;
            }
        }
        else if( nowCommand == start){
            commandBlock.push_back(line);
            ++counter;
            if(counter == N){
                nowCommand = stop;
                counter = 0;
            }
        }
    }
    notify();
};
