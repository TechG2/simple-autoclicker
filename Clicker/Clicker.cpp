#include <Windows.h>
#include <iostream>
#include "../other/values/values.h"
#include "../screens/menu/menu.h"

using namespace std;

class Clicker
{
private:
    int cps;
    ClickerStatusesType status;

public:
    Clicker(int cps)
    {
        this->cps;
    };

    // Get vars
    int getCPS()
    {
        return this->cps;
    }
    ClickerStatusesType getStatus()
    {
        return this->status;
    }

    // Set vars
    void setCPS(int cps)
    {
        this->cps = cps;
    }

    // Clicker methods
    void init()
    {
        this->status = getClickerStatus();
    }
    void startClicker(int key, int cps)
    {
        if (getStatus() == ClickerStatusesType::EnableClicker)
        {
            int disableShortcut = getShortcut(ShortcutsType::Disable);
            int delay = 10;

            while (true)
            {
                if (this->status == ClickerStatusesType::EnableClicker)
                {
                    if (GetAsyncKeyState(disableShortcut) & 0x0001)
                    {
                        disable();
                        break;
                    }

                    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                    Sleep(10);
                    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

                    Sleep((1000 - delay) / cps);
                }
            }
        }
    }

    void enable()
    {
        this->status = ClickerStatusesType::EnableClicker;
        setClickerStatus(ClickerStatusesType::EnableClicker);
        menu();
    }
    void disable()
    {
        this->status = ClickerStatusesType::DisableClicker;
        setClickerStatus(ClickerStatusesType::DisableClicker);
        menu();
    }
};