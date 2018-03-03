#pragma once

#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include "commadline.h"


class Observer {
public:
    virtual void update(std::string& lineCommand) = 0;
};


class TimeObserver : public Observer{
public:
    TimeObserver(CommandLine *cm, long N_ = 0) : bulkBegin(""), work(false), N(N_){
        cm->subscribe(this);
    }

    void update(std::string& lineCommand);

    void startBulk();

    void bulk();

private:
    std::vector<std::string> bulkBlock;
    std::string bulkBegin;
    bool work;
    long N;
};
