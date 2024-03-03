#ifndef MYWINDOWS_H_INCLUDE
#define MYWINDOWS_H_INCLUDE

#include<windows.h>

//初始化句柄
void iniHandle();

// 设置颜色
void setColor(int color);

// 设置光标位置
void setCursorPos(int x, int y);

// 隐藏光标
void hideCursor();

#endif // MYWINDOWS_H_INCLUDE