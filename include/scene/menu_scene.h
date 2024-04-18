#ifndef _MENU_SCENE_H_
#define _MENU_SCENE_H_

#include "scene.h"
#include "scene_manager.h"
#include "../timer/timer.h"

#include <iostream>

extern SceneManager scene_manager;
extern bool is_game_start;
extern bool running;
extern IMAGE img_menu_background;
extern Atlas atlas_player_right;

class MenuScene : public Scene
{
private:
    Timer timer;
    Camera camera;
    Animation animation;

public:
    MenuScene() = default;
    ~MenuScene() = default;

    void on_enter()
    {
        animation.set_atlas(&atlas_player_right);
        animation.set_interval(75);
        animation.set_loop(true);

        timer.set_wait_time(1000);
        timer.set_one_shot(false);
        timer.set_callback([]()
                           { std::cout << "MenuScene timer callback" << std::endl; });
    }

    void on_update(int delta)
    {
        timer.update(delta);
        camera.on_update(delta,player.GetPosition().x,player.GetPosition().y);
        animation.on_update(delta);
    }

    void on_draw()
    {
        putimage(0, 0, &img_menu_background);                              // 绘制背景图片
        outtextxy_shaded(600, 300, "游戏", 0, 0, 0, 50, 20, "黑体");       // 绘制游戏标题
        outtextxy_shaded(500, 600, "按空格开始", 0, 0, 0, 30, 30, "宋体"); // 绘制开始游戏按钮

        animation.on_draw(camera, 100, 100);
    }

    void on_input(const ExMessage &msg)
    {
        if (msg.message == WM_KEYDOWN)
        {
            camera.shake(10, 350);
        }
        switch (msg.message)
        {
        case WM_KEYUP:
            switch (msg.vkcode)
            {
            case VK_SPACE:
                scene_manager.switch_scene(SceneManager::SceneType::Game);
                is_game_start = false;
                break;
            case VK_ESCAPE:
                running = false;
                break;
            default:
                break;
            }
        }
    }

    void on_exit()
    {
    }
};

#endif // !_GAME_SCENE_H_