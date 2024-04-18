#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "scene.h"
#include "scene_manager.h"
#include "../player/player.h"
#include "../enemy/enemy_manager.h"
#include "../bullet/bullet.h"
#include "../camera.h"

extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;

#include <iostream>

extern bool is_game_start;
extern bool is_debug_mode;
extern size_t score;
extern IMAGE img_background;

extern Player player;
extern std::vector<Enemy *> enemy_list;
extern std::vector<Bullet *> bullet_list;
extern Camera main_camera;

extern SceneManager scene_manager;
extern EnemyManager enemy_manager;

// 函数声明
void shoot(std::vector<Enemy *> &enemy_list, const Player &player, std::vector<Bullet *> &bullet_list);
void TryGenerateEnemy();

class GameScene : public Scene
{
private:
    Timer timer;

public:
    GameScene() = default;
    ~GameScene() = default;

    void on_enter()
    {
        // 初始化玩家
        player.alive = true;
        player.HP = player.HP_MAX;
        player.position = POINT{WINDOW_WIDTH / 2 - PLAYER_WIDTH / 2, WINDOW_HEIGHT / 2 - PLAYER_HEIGHT / 2};
        player.is_strengthen = false;
        main_camera.reset_position();
    }

    void on_update(int delta)
    {
        // 全更新
        TryGenerateEnemy();
        shoot(enemy_list, player, bullet_list);
        timer.update(delta);

        // 全移动
        for (Enemy *enemy : enemy_list)
            enemy->Move(player);
        player.Move();
        for (Bullet *bullet : bullet_list)
            bullet->Move();

        // 全检测
        // 检测敌人玩家碰撞
        for (Enemy *enemy : enemy_list)
        {
            if (enemy->CheckPlayerConllision(player))
            {
                main_camera.set_callback([this]()
                                         {
                                             player.hurt();
                                             main_camera.set_shakeing(false);
                                             //
                                         });
                main_camera.shake(10, 350);
                // timer.set_wait_time(1000);
                // timer.set_one_shot(true);
            }
        }
        // 检测玩家存活
        if (player.isAlive() == false)
        {
            scene_manager.switch_scene(SceneManager::SceneType::GameOver);
            // MessageBox(GetHWnd(), _T("游戏结束"), _T("游戏结束"), MB_OK);
            is_game_start = false;
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

        main_camera.on_update(delta, player.GetPosition().x, player.GetPosition().y);
    }

    void on_draw()
    {
        // 绘制背景
        settextstyle(20, 10, "黑体"); // 设置字体样式和大小
        settextcolor(WHITE);

        const Vector2 &camera_pos = main_camera.get_position();
        putimage(0 - camera_pos.x, 0 - camera_pos.y, &img_background);

        // 显示分数
        std::string message = std::to_string(score);
        outtextxy(50, 50, "你的分数：");
        outtextxy(150, 50, message.c_str());
        // 显示玩家生命值
        std::string HP_message = std::to_string(player.HP);
        outtextxy(50, 100, "你的生命值：");
        outtextxy(150, 100, HP_message.c_str());
        if (is_debug_mode)
        {
            settextcolor(RED);
            outtextxy(200, 50, "调试模式");
        }

        // 显示玩家和敌人
        player.Draw(1000 / 144);
        for (Enemy *enemy : enemy_list)
            enemy->Draw(1000 / 144);
        for (Bullet *bullet : bullet_list)
            bullet->Draw();
    }

    void on_input(const ExMessage &msg)
    {
        player.ProcessEvent(msg);
        switch (msg.message)
        {
        case WM_KEYUP:
            switch (msg.vkcode)
            {
            case VK_ESCAPE:
                scene_manager.switch_scene(SceneManager::SceneType::GameOver);
                is_game_start = false;
                break;
            case 'P':
                break;
            case 'O':
                is_debug_mode = !is_debug_mode; // 打开调试模式
                break;
            default:
                break;
            }
            break;
        case WM_KEYDOWN:
            switch (msg.vkcode)
            {
            case 'J':
                player.is_strengthen = true;
                main_camera.set_callback([this]()
                                         {
                                             player.is_strengthen = false;
                                             main_camera.set_shakeing(false); });
                main_camera.shake(10, 550);
            }
            break;
        default:
            break;
        }
    }

    void on_exit()
    {
        // 释放内存
        if (!enemy_list.empty())
            enemy_list.clear();
        if (!bullet_list.empty())
            bullet_list.clear();
    }
};

// 敌人刷新
void TryGenerateEnemy()
{
    const int ENEMY_GENERATE_PROBABILITY = 10;
    static int counter = 0;
    if ((++counter) % ENEMY_GENERATE_PROBABILITY == 0)
    {
        enemy_manager.add_enemy_boar();
        // enemy_manager.add_enemy_knight();
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
    int BULLET_GENERATE_PROBABILITY = 10;
    if (player.is_strengthen)
        BULLET_GENERATE_PROBABILITY = 1;
    else
        BULLET_GENERATE_PROBABILITY = 10;
    static int counter = 0;
    if (nearestEnemy != nullptr)
    {
        if ((++counter) % BULLET_GENERATE_PROBABILITY == 0)
        {
            bullet_list.push_back(new Bullet(player, (nearestEnemy->position.x) + BOAR_WIDTH / 2, (nearestEnemy->position.y) + BOAR_HEIGHT / 2));
        }
    }
}

#endif // !_GAME_SCENE_H_