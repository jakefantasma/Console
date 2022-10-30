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
    void log(std::string msg)
    {
        std::cout << msg << std::endl;
        setColor(__default);
    };
    void log(int msg)
    {
        log(std::to_string(msg));
    };
    void error(std::string msg)
    {
        setColor(__error);
        log(msg);
    };
    void warning(std::string msg)
    {
        setColor(__warning);
        log(msg);
    };

    ~IMP();
};

IMP *Consola = new IMP();