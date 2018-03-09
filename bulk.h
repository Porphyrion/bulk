#pragma once
#include <ctime>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>

#define START 1
#define STOP 2
#define LAST_BULK 3
#define STRAT_DYNAMIC 11

namespace bulk
{
    class Observer{
    public:
        virtual void update(int s) = 0;
        virtual ~Observer(){};
    };

    class CommandLine{
    public:

        CommandLine(long N_):status(0),N(N_),dynamic(false) {};
        void notify();
        void subscribe(Observer* obs);
        void setStatus(int status);
        void appendCommnad(std::string& command);

        std::vector<std::string> commandBlock;

    private:
        std::vector<Observer *> subs;
        int status;
        bool dynamic;
        const long N;
    };

    //класс обозревателя для стандратного вывода
    class CoutObserver : public Observer{
    public:
        CoutObserver(std::shared_ptr<CommandLine> cm_): cm(cm_){
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
        LogObserver(std::shared_ptr<CommandLine> cm_) : cm(cm_){
            cm->subscribe(this);
            bulkBeginTime = "";
        };

        void update(int s);
    private:

        std::shared_ptr<CommandLine> cm;
        std::string bulkBeginTime;
        std::string bulkFileName;
    };

    //Интерпретатор комманд
    class Interpreter{
    public:
        Interpreter(std::shared_ptr<CommandLine> cl_, long N_) : cl(cl_), dynamic_counter(0){};

        void readCommand(std::string &command);

    private:
        std::shared_ptr<CommandLine> cl;
        long dynamic_counter;
    };
}
