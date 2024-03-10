#include <iostream>
#include <conio.h>
#include <easyx.h>
#include <math.h>
#include <cstring>
#include <vector>

//#include "scene.h"
// #include "game_scene.h"
#include "animation.h"
#include "player.h"
// #include "menu_scene.h"

// 当前动画帧索引
int idx_current_anim = 0;

int main()
{

    ExMessage msg;
    Player player;

    const int FPS = 60;

    initgraph(WINDOW_WIDTH, WINDOW_HEIGHT, 2);
    cleardevice();

    bool running = true;

    IMAGE img_background;
    loadimage(&img_background, _T("img/bkg/bkg.png"));

    BeginBatchDraw();

    // Scene *scene = new MenuScene();
    // scene->on_enter();

    // 游戏总循环
    while (running)
    {
        DWORD frame_start_time = GetTickCount();

        while (peekmessage(&msg))
        {
            //scene->on_input(msg);
            player.ProcessEvent(msg);
        }

        //scene->on_update();

        cleardevice();

        putimage(0, 0, &img_background);
        player.Draw(1000 / 144);

        //scene->on_draw();
        FlushBatchDraw();

        // 帧率
        DWORD frame_end_time = GetTickCount();
        DWORD frame_delta_time = frame_end_time - frame_start_time;
        if (frame_delta_time < 1000 / FPS)
            Sleep(1000 / FPS - frame_delta_time);
    }

    EndBatchDraw();

    return 0;
}