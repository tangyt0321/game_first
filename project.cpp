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

// 函数声明
void shoot(std::vector<Enemy *> &enemy_list, const Player &player, std::vector<Bullet *> &bullet_list);
void TryGenerateEnemy(std::vector<Enemy *> &enemy_list);

int main()
{
    load_game_sources();
    const int FPS = 60;
    // 初始化桌面
    initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);

    ExMessage msg;
    Player player;
    std::vector<Enemy *> enemy_list;
    std::vector<Bullet *> bullet_list;

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
            switch (scene_manager.get_current_scene_type())
            {
            case SceneManager::SceneType::Menu:
                break;
            case SceneManager::SceneType::Game:
                player.ProcessEvent(msg);
                break;
            case SceneManager::SceneType::GameOver:
                break;
            }
            scene_manager.on_input(msg);
        }

        static DWORD last_tick_time = GetTickCount();
        DWORD current_tick_time = GetTickCount();
        DWORD delta_time = current_tick_time - last_tick_time;
        scene_manager.on_update(delta_time);
        last_tick_time = current_tick_time;

        switch (scene_manager.get_current_scene_type())
        {
        case SceneManager::SceneType::Menu:
        {
            // 全更新
            scene_manager.on_update(delta_time);
            cleardevice();
            scene_manager.on_draw();
        }
        break;
        case SceneManager::SceneType::GameOver:
        {
            // 全更新
            scene_manager.on_update(delta_time);
            cleardevice();
            scene_manager.on_draw();
        }
        break;
        case SceneManager::SceneType::Game:
        {
            scene_manager.on_update(delta_time);
            // 全更新
            TryGenerateEnemy(enemy_list);
            shoot(enemy_list, player, bullet_list);

            // 全移动
            player.Move();
            for (Bullet *bullet : bullet_list)
                bullet->Move();
            for (Enemy *enemy : enemy_list)
                enemy->Move(player);

            // 全检测
            // 检测敌人玩家碰撞
            for (Enemy *enemy : enemy_list)
            {
                if (enemy->CheckPlayerConllision(player))
                {
                    scene_manager.set_current_scene(gameover_scene);
                    MessageBox(GetHWnd(), _T("游戏结束"), _T("游戏结束"), MB_OK);
                    is_game_start = false;
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
                        score += 1;
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
                    score += 100;
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
        }
        break;
        }

        FlushBatchDraw();
        // 帧率
        DWORD frame_end_time = GetTickCount();
        DWORD frame_delta_time = frame_end_time - frame_start_time;
        if (frame_delta_time < 1000 / FPS)
            Sleep(1000 / FPS - frame_delta_time);
    }

    EndBatchDraw();

    delete_game_resources();

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
