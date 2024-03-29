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
    MenuScene()
    {
        // 加载桌面背景图片
    }
    ~MenuScene() = default;

    void on_enter()
    {
        // std::cout << "进入主菜单" << std::endl;
    }

    void on_update()
    {
        // std::cout << "MenuScene update" << std::endl;
    }

    void on_draw()
    {
        // outtextxy(10, 10, _T("主菜单绘制内容"));
        setbkcolor(WHITE);
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