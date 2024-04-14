#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "scene.h"
#include "scene_manager.h"
#include "../player/player.h"
#include "../enemy/enemy_manager.h"
#include "../bullet/bullet.h"

extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;

#include <iostream>

extern bool is_game_start;
extern size_t score;
extern IMAGE img_background;

extern Player player;
extern std::vector<Enemy *> enemy_list;
extern std::vector<Bullet *> bullet_list;

extern SceneManager scene_manager;
extern EnemyManager enemy_manager;

// 函数声明
void shoot(std::vector<Enemy *> &enemy_list, const Player &player, std::vector<Bullet *> &bullet_list);
void TryGenerateEnemy();

class GameScene : public Scene
{
private:
public:
    GameScene()
    {
        // 加载桌面
        loadimage(&img_background, _T("resource/images/bkg/bkg.png"), WINDOW_WIDTH, WINDOW_HEIGHT);
    }
    ~GameScene() = default;

    void on_enter()
    {
        // 初始化玩家
        player.alive = true;
        player.HP = 100;
    }

    void on_update(int delta)
    {
        // 全更新
        TryGenerateEnemy();
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
                player.hurt();
                if (player.isAlive() == false)
                {
                    scene_manager.switch_scene(SceneManager::SceneType::GameOver);
                    // MessageBox(GetHWnd(), _T("游戏结束"), _T("游戏结束"), MB_OK);
                    is_game_start = false;
                    break;
                }
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
    }

    void on_draw()
    {
        // 绘制背景
        settextstyle(20, 10, "黑体"); // 设置字体样式和大小
        settextcolor(BLACK);
        putimage(0, 0, &img_background);
        // 显示分数
        std::string message = std::to_string(score);
        outtextxy(50, 50, "你的分数：");
        outtextxy(150, 50, message.c_str());
        // 显示玩家生命值
        std::string HP_message = std::to_string(player.HP);
        outtextxy(50, 100, "你的生命值：");
        outtextxy(150, 100, HP_message.c_str());

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
        case WM_KEYDOWN:
            switch (msg.vkcode)
            {
            case VK_ESCAPE:
                scene_manager.switch_scene(SceneManager::SceneType::GameOver);
                is_game_start = false;
                break;
            case 'P':
                std::cout << "GameScene pause" << std::endl;
                break;
            default:
                break;
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

#endif // !_GAME_SCENE_H_