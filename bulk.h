#pragma once
#include <ctime>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>

enum class Status{
    nothing,start, stop, last_bulk, start_dynamic
};

namespace bulk
{
    class CommandBlock;
    class Observer{
    public:
        Observer(std::shared_ptr<CommandBlock> cb_) : cb(cb_){};
        virtual void update(Status s) = 0;
        virtual ~Observer() = default;
        Observer(Observer && other) = default;
        std::shared_ptr<CommandBlock> cb;
    };


    class CommandBlock{
    public:

        CommandBlock(long N_):status(Status::nothing),N(N_),dynamic(false) {};
        void notify();
        void subscribe(std::unique_ptr<Observer> obs);
        void setStatus(Status status);
        void appendCommnad(std::string& command);

        std::vector<std::string> commands;

    private:
        std::vector<std::unique_ptr<Observer>> subs;
        Status status;
        bool dynamic;
        const long N;
    };

    //класс обозревателя для стандратного вывода
    class CoutObserver : public Observer{
    public:
        CoutObserver(std::shared_ptr<CommandBlock> cb_): Observer(cb_){
            //cb->subscribe(this);
        };
        ~CoutObserver() = default;
        void update(Status s) override;
    };

    //класс обозревателя для записи в лог
    class LogObserver : public Observer{
    public:
        LogObserver(std::shared_ptr<CommandBlock> cb_) : Observer(cb_){
            //cb->subscribe(this);
            bulkBeginTime = "";
        };
        ~LogObserver() = default;
        void update(Status s) override;

    private:
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
