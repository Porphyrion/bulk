#pragma once
#include <ctime>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>

#define start 1
#define stop 2
#define last_bulk 3

namespace bulk
{
    class Observer{
    public:
        virtual void update(int s) = 0;
        virtual ~Observer(){};
    };

    class CommandLine{
    public:

        CommandLine(long n_) : N(n_), nowCommand(0), dynamic(false), dynamic_counter(0){};
        void notify();
        void subscribe(Observer* obs);
        void Commnand(std::string& line);
        void setStatus(int status);

        std::vector<std::string> commandBlock;
    private:
        std::vector<Observer *> subs;
        int status;
        bool dynamic;
        long dynamic_counter;
        const long N;
    };

    //класс обозревателя для стандратного вывода
    class CoutObserver : public Observer{
    public:
        CoutObserver(std::shared_ptr<CommandLine> cm_){
            cm = cm_;
            cm->subscribe(this);
        };

        void update(int s);

    private:
        std::shared_ptr<CommandLine> cm;
        std::vector<std::string> bulkBlock;
    };

    //класс обозревателя для записи в лог
    class LogObserver : public Observer{
    public:
        LogObserver(std::shared_ptr<CommandLine> cm_){
            cm = cm_;
            cm->subscribe(this);
            bulkBeginTime = "";
        };

        void update(int s);
    private:

        std::shared_ptr<CommandLine> cm;
        std::string bulkBeginTime;
        std::string bulkFileName;
    };
}
