#include <iostream>
#include <conio.h>
#include <easyx.h>
#include <math.h>
#include <cstring>
#include <vector>

#include "include/Animation/Animation.h"
#include "include/player/player.h"
// #include "include/enemy/enemy.h"

#include "include/scene/scene.h"
#include "include/scene/scene_manager.h"
#include "include/scene/menu_scene.h"
#include "include/scene/game_scene.h"

// // 当前动画帧索引
// int idx_current_anim = 0;

Scene *menu_scene = nullptr;
Scene *game_scene = nullptr;

SceneManager scene_manager;

int main()
{

    ExMessage msg;
    Player player;

    const int FPS = 60;
    // 初始化桌面
    initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);
    setbkcolor(WHITE);

    // 游戏开始判定
    bool running = true;

    // 加载桌面
    // IMAGE img_background;
    // loadimage(&img_background, _T("resource/images/bkg/bkg.png"), WINDOW_WIDTH, WINDOW_HEIGHT);

    BeginBatchDraw();

    menu_scene = new MenuScene();
    game_scene = new GameScene();
    //设置场景为主菜单场景
    scene_manager.set_current_scene(menu_scene);

    // 游戏总循环
    while (running)
    {
        DWORD frame_start_time = GetTickCount();

        while (peekmessage(&msg))
        {
            scene_manager.on_input(msg);
            player.ProcessEvent(msg);
        }

        scene_manager.on_update();

        cleardevice();

        // putimage(0, 0, &img_background);

        player.Move();
        player.Draw(1000 / 144);
        scene_manager.on_draw();

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