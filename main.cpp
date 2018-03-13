#include <iostream>
#include <fstream>
#include <memory>
#include "bulk.h"

int main(int argc, char const *argv[]) {

    long N = atoi(argv[1]);

    auto cb = std::make_shared<bulk::CommandBlock>(N);
    bulk::CoutObserver ob(cb);
    bulk::LogObserver lo(cb);
    bulk::Interpreter inter(cb, N);
    //std::ofstream bulkFileMain("main.log");
    //auto i = 0;
    std::string line;
    while(std::getline(std::cin, line)){
        //if(i>6) break;
        //bulkFileMain<<line<<" ";
        inter.readCommand(line);
        //i++;
    }
    cb->setStatus(LAST_BULK);
    return 0;
}

/*
0
1
2
3
4
{
00
}
*/
