#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>

HANDLE CMD_HANDLER = GetStdHandle(STD_OUTPUT_HANDLE);

class IMP
{
private:
    int __default = 7;
    int __error = 4;
    int __warning = 6;

public:
    IMP(){};
    void setColor(int color)
    {
        SetConsoleTextAttribute(CMD_HANDLER, color);
    }
    // main write log
    void log(std::string msg) // string
    {
        std::cout << msg << std::endl;
        setColor(__default);
    };
    void log(int msg) // int
    {
        log(std::to_string(msg));
    };
    void log(char msg) // char
    {
        std::string s(1, msg);
        log(s);
    };
    // main write error
    void error(std::string msg) // string
    {
        setColor(__error);
        log(msg);
    };
    void error(int msg) // string
    {
        error(std::to_string(msg));
    }
    void error(char msg) // char
    {
        std::string s(1, msg);
        error(s);
    }
    void warning(std::string msg) // string
    {
        setColor(__warning);
        log(msg);
    };
    void warning(char msg) // char
    {
        std::string s(1, msg);
        warning(s);
    }
    void warning(int msg) // int
    {
        warning(std::to_string(msg));
    };
    // string
    ~IMP();
};

IMP *Consola = new IMP();