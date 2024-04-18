#include <iostream>
#include <conio.h>
#include <math.h>

#include "load.h"
#include "delete.h"

#include "include/Animation/Animation.h"

int WINDOW_WIDTH = 1280;
int WINDOW_HEIGHT = 720;
int random_id = 0;

SceneManager scene_manager;
EnemyManager enemy_manager;
// BulletManager bullet_manager;

// 游戏开始判定
bool is_game_start = false;
bool running = true;
bool is_debug_mode = false; // 调试模式
size_t score = 0;

int main()
{
    load_game_sources();
    const int FPS = 30;
    // 初始化桌面
    initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);
    setbkmode(TRANSPARENT);

    ExMessage msg;

    BeginBatchDraw();

    menu_scene = new MenuScene();
    game_scene = new GameScene();
    // upgrade_scene = new UpgradeScene();
    gameover_scene = new GameoverScene();

    // 设置场景为主菜单场景
    scene_manager.set_current_scene(menu_scene);

    // 游戏总循环
    while (running)
    {
        DWORD frame_start_time = GetTickCount();

        // 处理输入
        while (peekmessage(&msg))
        {
            scene_manager.on_input(msg);
        }

        // 更新场景
        static DWORD last_tick_time = GetTickCount();
        DWORD current_tick_time = GetTickCount();
        DWORD delta_time = current_tick_time - last_tick_time;
        scene_manager.on_update(delta_time);
        last_tick_time = current_tick_time;

        // 绘制场景
        cleardevice();
        scene_manager.on_draw();

        random_id = random_id + 1000;
        // 刷新缓冲区
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
