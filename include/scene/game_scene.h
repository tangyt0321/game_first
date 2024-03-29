#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "scene.h"
#include "scene_manager.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#include <iostream>

extern SceneManager scene_manager;
extern bool is_game_start;

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
        Player player;
        std::vector<Enemy *> enemy_list;
        std::vector<Bullet *> bullet_list;
        is_game_start = true;
    }

    void on_update()
    {
        // std::cout << "GameScene update" << std::endl;
    }

    void on_draw()
    {
        putimage(0, 0, &img_background);
        // std::cout << "GameScene draw" << std::endl;
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