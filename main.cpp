#include <iostream>
#include <ctime>
#include <vector>
#include "commadline.h"
#include "observer.h"


int main(int argc, char const *argv[]) {
    CommandLine cml;
    long N = atoi(argv[1]);
    TimeObserver ob(&cml, N);
    std::string line;
    while(std::getline(std::cin, line)){
        cml.setCommnand(line);
    }

    return 0;
}
