#include "values.h"
#include <winuser.h>

// Other
ClickerStatusesType clickerStatus = ClickerStatusesType::DisableClicker;

ClickerStatusesType getClickerStatus()
{
    return clickerStatus;
}
void setClickerStatus(ClickerStatusesType status)
{
    clickerStatus = status;
}

// CPS
int cpsValue = 5;

int getCPS()
{
    return cpsValue;
}
void setCPS(int num)
{
    cpsValue = num;
}

// Shortcut
int shortcutEnable = VK_F6;
int shortcutDisable = VK_F4;

int getShortcut(ShortcutsType type)
{
    int currentValue;

    if (type == ShortcutsType::Enable)
        currentValue = shortcutEnable;
    if (type == ShortcutsType::Disable)
        currentValue = shortcutDisable;

    return currentValue;
}