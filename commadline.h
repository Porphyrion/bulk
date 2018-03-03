#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "observer.h"

class CommandLine{
public:

    void notify();
    void subscribe(Observer *obs);

    void setCommnand(std::string& line);

private:
    std::vector<Observer *> subs;
    std::string nowLine;
};
