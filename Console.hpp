#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
HANDLE CMD_HANDLER = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
class IMP
{
private:
    int __default = 7;
    int __error = 4;
    int __warning = 6;

public:
    IMP(){};
    void gotoxy(int x, int y)
    {
        CursorPosition.X = x;
        CursorPosition.Y = y;
        SetConsoleCursorPosition(CMD_HANDLER, CursorPosition);
    }
    void setColor(int color)
    {
        SetConsoleTextAttribute(CMD_HANDLER, color);
    }
    template <typename T>
    void log(T msg) // string
    {
        std::cout << msg << std::endl;
        setColor(__default);
    };
    template <typename T>
    void error(T msg) // string
    {
        setColor(__error);
        log(msg);
    };
    template <typename T>
    void warning(T msg) // string
    {
        setColor(__warning);
        log(msg);
    };
    void setTitle(std::string title)
    {
        SetConsoleTitle(title.c_str());
    }
    ~IMP();
};

IMP *Console = new IMP();