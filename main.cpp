#include "./Console.hpp"
#include "windows.h"
int main()
{
    int r = 0;
    while (true)
    {
        Consola->gotoxy(20, 10);
        Consola->error(r);
        Consola->gotoxy(20, 11);
        Consola->warning("warning 1");

        r +=1;
        Sleep(100);
    }

    // Consola->error("error 1");
    // Consola->error(key);
    // Consola->warning("warning 1");
}