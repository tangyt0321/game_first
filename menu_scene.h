#ifndef _MENU_SCENE_H_
#define _MENU_SCENE_H_

#include "scene.h"
#include <iostream>

class MenuScene : public Scene
{

public:
    MenuScene() = default;
    ~MenuScene() = default;

    virtual void on_enter()
    {
        std::cout << "进入主菜单" << std::endl;
    }

    virtual void update()
    {
        std::cout << "MenuScene update" << std::endl;
    }

    virtual void draw()
    {
        outtextxy(10, 10, _T("主菜单绘制内容"));
    }

    virtual void on_input(const ExMessage &msg)
    {
    }

    virtual void on_exit()
    {
        std::cout << "MenuScene exit" << std::endl;
    }
};

#endif // !_GAME_SCENE_H_