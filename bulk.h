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

namespace bulk
{
    class Observer{
    public:
        virtual void update(int s) = 0;
        virtual ~Observer(){};
    };

    //класс обработки команд из командной строки
    class CommandLine{
    public:

        CommandLine(long n_) : N(n_), status(0), dynamic(false), dynamic_counter(0){};
        void notify();
        void subscribe(Observer* obs);
        void Commnand(std::string& line);
        void setStatus(int status);

        std::vector<std::string> commandBlock;

    private:
        std::vector<Observer *> subs;

        int status;
        bool dynamic;
        long dynamic_counter;//счетчик открытых/закрытых скобок при динамическом изменнии размера блока
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
