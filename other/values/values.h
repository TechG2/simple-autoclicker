#ifndef VALUES_H
#define VALUES_H

// Other
bool clickerEnabled = false;

enum ClickerStatusesType
{
    EnableClicker = 0,
    DisableClicker = 1
};

ClickerStatusesType getClickerStatus();
void setClickerStatus(ClickerStatusesType status);

// CPS
extern int cpsValue;

int getCPS();
void setCPS(int num);

// Shortcuts
enum ShortcutsType
{
    Enable = 0,
    Disable = 1
};

int getShortcut(enum ShortcutsType type);

#endif // VALUES_H
