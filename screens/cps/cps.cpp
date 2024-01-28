#include <iostream>
#include <Windows.h>
#include <string>
#include "cps.h"
#include "../menu/menu.h"
#include "../../other/values/values.h"

using namespace std;
void cps()
{
    // Var
    int cpsNum = getCPS();

    string str = "....................";
    str.replace(0, cpsNum, cpsNum, '-');

    // Dysplay
    system("cls");
    cout << "Test Clicker" << endl
         << endl;
    cout << "Set the cps." << endl
         << endl;
    cout << "Current CPS: " << cpsNum << endl;
    cout << "<{|" << str << "|}>" << endl
         << endl;
    cout << "ShortCuts:" << endl;
    cout << "[ENTER] Apply Changes" << endl;
    cout << "[ESCAPE] Back to Menu";

    // Check key press
    while (true)
    {
        if (GetAsyncKeyState(VK_LEFT) & 0x0001)
        {
            if (cpsNum == 0)
                continue;

            setCPS(cpsNum - 1);
            cps();
            break;
        }
        else if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
        {
            if (cpsNum == 20)
                continue;

            setCPS(cpsNum + 1);
            cps();
            break;
        }
        else if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
        {
            menu();
            break;
        }
        else if (GetAsyncKeyState(VK_RETURN) & 0x0001)
        {
            menu();
            break;
        }
    }
}