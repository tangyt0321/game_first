#ifndef _MENU_SCENE_H_
#define _MENU_SCENE_H_

#include "scene.h"
#include "scene_manager.h"

#include <iostream>

extern SceneManager scene_manager;
extern bool is_game_start;
extern bool running;
extern IMAGE img_menu_background;

class MenuScene : public Scene
{

public:
    MenuScene() = default;
    ~MenuScene() = default;

    void on_enter()
    {
    }

    void on_update(int delta)
    {
    }

    void on_draw()
    {
        putimage(0, 0, &img_menu_background);                              // 绘制背景图片
        outtextxy_shaded(600, 300, "游戏", 0, 0, 0, 50, 20, "黑体");       // 绘制游戏标题
        outtextxy_shaded(500, 600, "按空格开始", 0, 0, 0, 30, 30, "宋体"); // 绘制开始游戏按钮
    }

    void on_input(const ExMessage &msg)
    {

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