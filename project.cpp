#include <iostream>
#include <conio.h>
#include <math.h>

#include "load.h"
#include "delete.h"

#include "include/Animation/Animation.h"

SceneManager scene_manager;

// 游戏开始判定
bool is_game_start = false;
bool running = true;
size_t score = 0;

Player player;
std::vector<Enemy *> enemy_list;
std::vector<Bullet *> bullet_list;

int main()
{
    load_game_sources();
    const int FPS = 60;
    // 初始化桌面
    initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);

    ExMessage msg;

    BeginBatchDraw();

    menu_scene = new MenuScene();
    game_scene = new GameScene();
    gameover_scene = new GameoverScene();

    // 设置场景为主菜单场景
    scene_manager.set_current_scene(menu_scene);

    // 游戏总循环
    while (running)
    {
        DWORD frame_start_time = GetTickCount();

        while (peekmessage(&msg))
        {
            scene_manager.on_input(msg);
        }

        static DWORD last_tick_time = GetTickCount();
        DWORD current_tick_time = GetTickCount();
        DWORD delta_time = current_tick_time - last_tick_time;
        scene_manager.on_update(delta_time);
        last_tick_time = current_tick_time;

        cleardevice();
        scene_manager.on_draw();

        FlushBatchDraw();
        // 帧率
        DWORD frame_end_time = GetTickCount();
        DWORD frame_delta_time = frame_end_time - frame_start_time;
        if (frame_delta_time < 1000 / FPS)
            Sleep(1000 / FPS - frame_delta_time);
    }

    EndBatchDraw();

    // 释放资源
    delete_game_resources();

    return 0;
}
