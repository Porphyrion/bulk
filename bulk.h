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
#define START_DYNAMIC 11

enum class Status{
    nothing,start, stop, last_bulk, start_dynamic
};

namespace bulk
{
    
    class Observer{
    public:
        virtual void update(Status s) = 0;
        virtual ~Observer(){};
    };
    
    class CommandBlock{
    public:
        
        CommandBlock(long N_):status(Status::nothing),N(N_),dynamic(false) {};
        void notify();
        void subscribe(Observer* obs);
        void setStatus(Status status);
        void appendCommnad(std::string& command);
        
        std::vector<std::string> commands;
        
    private:
        std::vector<Observer *> subs;
        Status status;
        bool dynamic;
        const long N;
    };
    
    //класс обозревателя для стандратного вывода
    class CoutObserver : public Observer{
    public:
        CoutObserver(std::shared_ptr<CommandBlock> cb_): cb(cb_){
            cb->subscribe(this);
        };
        
        void update(Status s);
        
    private:
        std::shared_ptr<CommandBlock> cb;
    };
    
    //класс обозревателя для записи в лог
    class LogObserver : public Observer{
    public:
        LogObserver(std::shared_ptr<CommandBlock> cb_) : cb(cb_){
            cb->subscribe(this);
            bulkBeginTime = "";
        };
        
        void update(Status s);
    private:
        
        std::shared_ptr<CommandBlock> cb;
        std::string bulkBeginTime;
        std::string bulkFileName;
    };
    
    //Интерпретатор комманд
    class Interpreter{
    public:
        Interpreter(std::shared_ptr<CommandBlock> cb_, long N_) : cb(cb_), dynamic_counter(0){};
        
        void readCommand(std::string &command);
        
    private:
        std::shared_ptr<CommandBlock> cb;
        long dynamic_counter;
    };
}
