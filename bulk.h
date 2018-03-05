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
#define work 3
#define dynamic_start 11
#define dont_work 99
#define dynamic_work 88


namespace bulk
{
    class Observer{
    public:
        virtual void update(int s) = 0;
        virtual ~Observer(){};
    };

    class CommandLine{
    public:

        CommandLine(long n_) : N(n_), nowCommand(dont_work), counter(0), dynamic_counter(0){};
        void notify();
        void subscribe(Observer *obs);
        void setCommnand(std::string& line);

        std::vector<std::string> commandBlock; // retutn unique_ptr
    private:
        std::vector<bulk::Observer *> subs;
        int nowCommand;
        long counter;
        long dynamic_counter;
        const long N;
    };

    //класс обозревателя для стандратного вывода
    class CoutObserver : public Observer{
    public:
        CoutObserver(CommandLine *cm_){
            cm = cm_;
            cm->subscribe(this);
        };

        void update(int s);

    private:
        CommandLine * cm;
        std::vector<std::string> bulkBlock;
    };

    //класс обозревателя для записи в лог
    class LogObserver : public Observer{
    public:
        LogObserver(CommandLine *cm_){
            cm = cm_;
            cm->subscribe(this);
            bulkBeginTime = "";
        };

        void update(int s);
    private:

        CommandLine * cm;
        std::string bulkBeginTime;
    };
}
