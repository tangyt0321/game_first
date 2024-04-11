#ifndef _MENU_SCENE_H_
#define _MENU_SCENE_H_

#include "scene.h"
#include "scene_manager.h"

#include <iostream>

extern SceneManager scene_manager;
extern bool is_game_start;

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
        settextstyle(50, 20, "黑体"); // 设置字体样式和大小
        settextcolor(BLACK);
        setbkcolor(WHITE);
        outtextxy(600, 300, "游戏");

        settextstyle(20, 30, "宋体"); // 设置字体样式和大小
        settextcolor(BLACK);
        outtextxy(500, 600, "按空格开始");
    }

    void on_input(const ExMessage &msg)
    {

        switch (msg.message)
        {
        case WM_KEYDOWN:
            switch (msg.vkcode)
            {
            case VK_SPACE:
                std::cout << "切换到游戏场景" << std::endl;
                scene_manager.switch_scene(SceneManager::SceneType::Game);
                is_game_start = false;
                break;
            default:
                break;
            }
        }
    }

    void on_exit()
    {
        // std::cout << "MenuScene exit" << std::endl;
    }
};

#endif // !_GAME_SCENE_H_