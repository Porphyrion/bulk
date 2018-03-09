#include <iostream>
#include <memory>
#include "bulk.h"

int main(int argc, char const *argv[]) {
    
    long N = atoi(argv[1]);
    
    auto cb = std::make_shared<bulk::CommandBlock>(N);
    bulk::CoutObserver ob(cb);
    bulk::LogObserver lo(cb);
    bulk::Interpreter inter(cb, N);
    
    
    std::string line;
    while(std::getline(std::cin, line)){
        inter.readCommand(line);
    }
    cb->setStatus(LAST_BULK);
    return 0;
}
