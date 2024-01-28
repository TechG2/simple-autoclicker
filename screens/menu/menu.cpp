#include <iostream>
#include <Windows.h>
#include "menu.h"
#include "../cps/cps.h"
#include "../../other/values/values.h"
#include "../../Clicker/Clicker.cpp"

using namespace std;
void menu()
{
    // Var clicker
    Clicker clicker(getCPS());
    clicker.init();
    string status = (clicker.getStatus() == ClickerStatusesType::EnableClicker) ? "Enable" : "Disable";

    // Display
    system("cls");
    cout << "Test Clicker";
    cout << endl
         << endl;

    cout << "Info:" << endl;
    cout << "Status: " << status << endl;
    cout << "CPS: " << getCPS() << endl;
    cout << "Enable Shortcut: F6" << endl;
    cout << "Disable Shortcut: F4" << endl;
    cout << endl
         << endl;

    cout << "ShortCut:" << endl;
    cout << "[C] CPS" << endl;
    cout << "[Shift+X] Self-Destruct" << endl;
    cout << "[ESCAPE] Close" << endl;

    // Check clicker
    clicker.startClicker(VK_LBUTTON, getCPS());

    // Check key press
    while (true)
    {
        if (GetAsyncKeyState('C') & 0x0001)
        {
            cps();
            break;
        }
        if (GetAsyncKeyState(VK_F6) & 0x0001)
        {
            clicker.enable();
            break;
        }
        if (GetAsyncKeyState(VK_F4) & 0x0001)
        {
            clicker.disable();
            menu();
            break;
        }
        if (GetAsyncKeyState('X') & 0x0001)
        {
            exit(0);
        }
        if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
            exit(0);
    }
}