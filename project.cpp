#include <iostream>
#include <conio.h>
#include <easyx.h>
#include <math.h>

// #pragma comment(lib, "winmm.lib")

#include "load.h"

#include "include/Animation/Animation.h"

#include "include/scene/scene.h"
#include "include/scene/scene_manager.h"
#include "include/scene/menu_scene.h"
#include "include/scene/game_scene.h"

void shoot(std::vector<Enemy *> &enemy_list, const Player &player, std::vector<Bullet *> &bullet_list);

//  当前动画帧索引
// int idx_current_anim = 0;

Scene *menu_scene = nullptr;
Scene *game_scene = nullptr;

SceneManager scene_manager;

void TryGenerateEnemy(std::vector<Enemy *> &enemy_list);

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
    std::vector<Enemy *> enemy_list;
    std::vector<Bullet *> bullet_list;

    BeginBatchDraw();

    menu_scene = new MenuScene();
    game_scene = new GameScene();
    // 设置场景为主菜单场景
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
        // 全更新
        scene_manager.on_update();
        TryGenerateEnemy(enemy_list);
        shoot(enemy_list, player, bullet_list);
        // 全移动
        player.Move();
        for (Bullet *bullet : bullet_list)
            bullet->Move();
        for (Enemy *enemy : enemy_list)
            enemy->Move(player);

        // 检测敌人玩家碰撞
        for (Enemy *enemy : enemy_list)
        {
            if (enemy->CheckPlayerConllision(player))
            {
                scene_manager.set_current_scene(menu_scene);
                MessageBox(GetHWnd(), _T("游戏结束"), _T("游戏结束"), MB_OK);
                running = false;
                break;
            }
        }
        // 检测子弹和敌人碰撞
        for (Enemy *enemy : enemy_list)
        {   
            size_t i = 0;
            for (const Bullet *bullet : bullet_list)
            {
                if (enemy->CheckBulletConllision(bullet))
                {
                    enemy->hurt();
                    std::swap(bullet_list[i], bullet_list.back());
                    bullet_list.pop_back();
                    break;
                }
                i++;
            }
        }
        // 移除生命值归零的敌人
        for (size_t i = 0; i < enemy_list.size(); i++)
        {
            Enemy *enemy = enemy_list[i];
            if (!enemy->isAlive())
            {
                std::swap(enemy_list[i], enemy_list.back());
                enemy_list.pop_back();
                delete enemy;
            }
        }

        cleardevice();

        // 全绘制
        scene_manager.on_draw();
        player.Draw(1000 / 144);
        for (Enemy *enemy : enemy_list)
            enemy->Draw(1000 / 144);
        for (Bullet *bullet : bullet_list)
            bullet->Draw();
        FlushBatchDraw();

        // 帧率
        DWORD frame_end_time = GetTickCount();
        DWORD frame_delta_time = frame_end_time - frame_start_time;
        if (frame_delta_time < 1000 / FPS)
            Sleep(1000 / FPS - frame_delta_time);
    }

    delete atlas_player_left;
    delete atlas_player_right;
    delete atlas_enemy_left;
    delete atlas_enemy_right;

    EndBatchDraw();

    return 0;
}

// 敌人刷新
void TryGenerateEnemy(std::vector<Enemy *> &enemy_list)
{
    const int ENEMY_GENERATE_PROBABILITY = 100;
    static int counter = 0;
    if ((++counter) % ENEMY_GENERATE_PROBABILITY == 0)
    {
        enemy_list.push_back(new Enemy());
    }
}

// 子弹发射
void shoot(std::vector<Enemy *> &enemy_list, const Player &player, std::vector<Bullet *> &bullet_list)
{
    const POINT &player_pos = player.GetPosition();
    if (enemy_list.empty())
        return; // 如果没有怪物，则不发射子弹
    // 找到最近的怪物
    double minDistance = WINDOW_WIDTH * WINDOW_WIDTH + WINDOW_HEIGHT * WINDOW_HEIGHT;
    Enemy *nearestEnemy = nullptr;
    for (Enemy *enemy : enemy_list)
    {
        double distance = (enemy->position.x - player_pos.x) * (enemy->position.x - player_pos.x) + (enemy->position.y - player_pos.y) * (enemy->position.y - player_pos.y);
        if (distance <= minDistance)
        {
            minDistance = distance;
            nearestEnemy = enemy;
        }
    }
    // 发射子弹
    const int BULLET_GENERATE_PROBABILITY = 3;
    static int counter = 0;
    if (nearestEnemy != nullptr)
    {
        if ((++counter) % BULLET_GENERATE_PROBABILITY == 0)
        {
            bullet_list.push_back(new Bullet(player, (nearestEnemy->position.x) + BOAR_WIDTH / 2, (nearestEnemy->position.y) + BOAR_HEIGHT / 2));
        }
    }
}
