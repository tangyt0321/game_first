#ifndef GAME_H_INCLUDE
#define GAME_H_INCLUDE

/*游戏逻辑模块*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 方块结构体
typedef struct
{
    int x;
    int y;
    int shape;
    int status;
    int color;
} BLOCK;

// 1.绘制游戏池边框
void windowPrint(int x, int y);

// 2.游戏初始化
void gameInit();

// 3.打印操作说明
void printInfo();

// 4.打印分数和登记
void printPrintScore(int num);

// 5.游戏计时
void gameTime(clock_t start_time);

// 6.左边框
void leftBorder();

// 7.打印方块
void printBlock(BLOCK block);

// 8.删除方块
void deleteBlock(BLOCK block);

// 9.产生游戏第一个方块
void generateBlock();

// 10.产生下一个方块
void nextBlock();

// 11.拷贝方块
void copyBlock(BLOCK block);

// 12.移动方块
int doneBlock();
void leftBlock();
void rightBlock();

// 15.旋转方块
void rotateBlock();

// 16.方块直接落底
void dropBlock(int n);

// 17.碰撞检测
void crash(BLOCK block);

// 18.方块保存
void saveBlock();

// 19.刷新游戏池
void upGradeGame();

// 20.游戏暂停
void gamePause();

// 21.消行检测
void checkLine();

// 22.消行下移
void lineDown(int line);

// 23.游戏结束动画
void gameOver();

// 24.游戏重开提示
void gameRestart();

// 25.游戏重开
void gameAgain();

// 26.游戏结束界面
void gameOverPrint();

// 27.打印开始图案
void startPrint(int x, int y);

// 28.清除开始动画
void deleteStart(int x, int y);

// 29.动画效果  定时（边界）
void animation();

// 30.游戏模式
void gameMode(float time, int n);

// 31.游戏模式选择界面
void gameModePrint();

#endif // GAME_H_INCLUDE