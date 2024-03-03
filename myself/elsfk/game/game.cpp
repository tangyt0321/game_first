#include <iostream>
using namespace std;
//#include "game.h"
#include "mywindows.h"
#include <conio.h>
// #include<windows.h>
#include <time.h>

//#include <mmsystem.h>
// #pragma comment(lib,"winmm.lib")

int grade = 0;                             // 分数
int level = 1;                             // 等级
int one = 0, two = 0, three = 0, four = 0; // 消的行数
//clock_t start, time;

//BLOCK cur_block;  // 当前方块
//BLOCK next_block; // 下一个方块

// 绘制游戏池
void windowPrint(int x, int y)
{

}


int main()
{
    clock_t time_now, time_end;
    int j;
    double temp;
    time_now = clock();//记录第一次调用clock()的时间

    for (int j = 0; j < 10000;j++)
    {
        time_end = clock();
        temp = (double)(time_end - time_now) / CLOCKS_PER_SEC;
        cout << "进程使用时间为"<<temp <<"秒"<< endl;
    }
        return 0;
}