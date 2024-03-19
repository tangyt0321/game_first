#include <iostream>
#include <conio.h>
#include <easyx.h>
#include <math.h>

// #pragma comment(lib, "winmm.lib")

#include "load.h"

#include "include/Animation/Animation.h"
#include "include/player/player.h"

// #include "include/enemy/enemy.h"

#include "include/scene/scene.h"
#include "include/scene/scene_manager.h"
#include "include/scene/menu_scene.h"
#include "include/scene/game_scene.h"

//  当前动画帧索引
// int idx_current_anim = 0;

Scene *menu_scene = nullptr;
Scene *game_scene = nullptr;

SceneManager scene_manager;

int main()
{
    load_game_sources();
    bool running = true;

    const int FPS = 60;
    // 初始化桌面
    initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);
    setbkcolor(WHITE);

    // 游戏开始判定

    // bool is_game_start = false;
    ExMessage msg;
    Player player;
    BeginBatchDraw();
    // std::cout << "Hello World!\n";
    menu_scene = new MenuScene();
    game_scene = new GameScene();
    // 设置场景为主菜单场景
    scene_manager.set_current_scene(menu_scene);
    // std::cout << "Hello World!\n";
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

        scene_manager.on_draw();
        player.Move();
        player.Draw(1000 / 144);

        FlushBatchDraw();

        // 帧率
        DWORD frame_end_time = GetTickCount();
        DWORD frame_delta_time = frame_end_time - frame_start_time;
        if (frame_delta_time < 1000 / FPS)
            Sleep(1000 / FPS - frame_delta_time);
    }

    delete atlas_player_left;
    delete atlas_player_right;

    EndBatchDraw();

    return 0;
}