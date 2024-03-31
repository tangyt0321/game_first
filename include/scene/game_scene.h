#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "scene.h"
#include "scene_manager.h"
#include "../player/player.h"
#include "../enemy/enemy.h"
#include "../bullet/bullet.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#include <iostream>

extern SceneManager scene_manager;
// extern Animation anim_player;
// extern Atlas atlas_player_right;
extern bool is_game_start;
extern size_t score;

class GameScene : public Scene
{
private:
    IMAGE img_background;

public:
    GameScene()
    {
        // 加载桌面
        loadimage(&img_background, _T("resource/images/bkg/bkg.png"), WINDOW_WIDTH, WINDOW_HEIGHT);
    }
    ~GameScene() = default;

    void on_enter()
    {
        // std::cout << "GameScene enter" << std::endl;
        // Player player;
        // std::vector<Enemy *> enemy_list;
        // std::vector<Bullet *> bullet_list;
    }

    void on_update(int delta)
    {
        // anim_player.on_update(delta);
    }

    void on_draw()
    {
        settextstyle(20, 10, "黑体"); // 设置字体样式和大小
        settextcolor(BLACK);
        putimage(0, 0, &img_background);
        // 显示分数
        std::string message = std::to_string(score);
        outtextxy(50, 50, "你的分数：");
        outtextxy(150, 50, message.c_str());

        // 显示玩家
        // anim_player.on_draw(100, 100);
    }

    void on_input(const ExMessage &msg)
    {
        switch (msg.message)
        {
        case WM_KEYDOWN:
            switch (msg.vkcode)
            {
            case VK_ESCAPE:
                std::cout << "GameScene exit" << std::endl;
                scene_manager.switch_scene(SceneManager::SceneType::GameOver);
                is_game_start = false;
                on_exit();
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
        // delete player;
        // if (enemy_list.empty())
        //     return;
        // for (Enemy *enemy : enemy_list)
        // {
        //     delete enemy;
        // }
        // if (bullet_list.empty())
        //     return;
        // for (Bullet *bullet : bullet_list)
        // {
        //     delete bullet;
        // }
    }
};

#endif // !_GAME_SCENE_H_