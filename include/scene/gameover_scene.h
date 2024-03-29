#pragma once

#include "scene.h"
#include "scene_manager.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#include <iostream>

extern SceneManager scene_manager;
extern bool is_game_start;

class GameoverScene : public Scene
{
private:
public:
    GameoverScene()
    {
        // 加载桌面
    }
    ~GameoverScene() = default;

    void on_enter()
    {
    }

    void on_update()
    {
    }

    void on_draw()
    { 
        // 加载桌面
        setbkcolor(BLACK);
    }

    void on_input(const ExMessage &msg)
    {
        switch (msg.message)
        {
        case WM_KEYDOWN:
            switch (msg.vkcode)
            {
            case VK_ESCAPE:
                scene_manager.switch_scene(SceneManager::SceneType::Menu);
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
    }
};