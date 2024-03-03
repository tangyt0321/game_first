#include "mywindows.h"

HANDLE handle;

// 初始化句柄
void iniHandle()
{
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    hideCursor()
}

// 设置颜色
void setColor(int color)
{
    SetConsoleTextAttribute(handle, color);
}

// 设置光标位置
void setCursorPos(int x, int y)
{
    COORD coord = {x * 2, y};
    SetConsoleCursorPosition(handle, coord);
}

// 隐藏光标
void hideCursor()
{
    CONSOLE_CURSOR_INFO info;
    info.bVisible = false; // 设置光标
    info.dwSize = 1;
}