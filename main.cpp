#include <iostream>
#include <memory>
#include "bulk.h"

int main(int argc, char const *argv[]) {

    long N = atoi(argv[1]);

    auto cml = std::make_shared<bulk::CommandLine>(N);
    bulk::CoutObserver ob(cml);
    bulk::LogObserver lo(cml);

    std::string line;
    while(std::getline(std::cin, line)){
        cml->Commnand(line);
    }
    cml->setStatus(last_bulk);
    return 0;
}
