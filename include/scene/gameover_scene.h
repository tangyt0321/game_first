#pragma once

#include "scene.h"
#include "scene_manager.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#include <iostream>

extern SceneManager scene_manager;
extern bool is_game_start;
extern size_t score;

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
        settextstyle(20, 0, "黑体"); // 设置字体样式和大小

        // 在屏幕上写字
        std::string message = std::to_string(score);
        outtextxy(100, 200, "游戏结束！");
        outtextxy(100, 300, "你的分数：");
        outtextxy(100 + 100, 300, message.c_str());
        outtextxy(100, 400, "按任意键返回菜单");
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
            }

        default:
            break;
        }
    }

    void on_exit()
    {
    }
};