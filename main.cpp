#include <iostream>
#include <memory>
#include "bulk.h"

int main(int argc, char const *argv[]) {

    long N = atoi(argv[1]);

    auto cml = std::make_shared<bulk::CommandLine>(N);
    bulk::CoutObserver ob(cml);
    bulk::LogObserver lo(cml);
    bulk::Interpreter inter(cml, N);


    std::string line;
    while(std::getline(std::cin, line)){
        inter.readCommand(line);
    }
    cml->setStatus(LAST_BULK);
    return 0;
}
