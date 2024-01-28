#ifndef CLICKER_H
#define CLICKER_H

#include <Windows.h>
#include <iostream>

enum ClickerStatusesType
{
    EnableClicker = 0,
    DisableClicker = 1
};

class Clicker
{
private:
    int cps;
    ClickerStatusesType status = DisableClicker;

public:
    Clicker(int cps);

    // Get vars
    int getCPS();

    // Set vars
    void setCPS(int cps);

    // Clicker methods
    void init();
    void startClicker();
    void enable();
    void disable();
};

#endif // CLICKER_H
