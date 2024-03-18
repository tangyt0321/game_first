#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "scene.h"
#include "scene_manager.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#include <iostream>

extern SceneManager scene_manager;

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
        if (msg.message == VK_ESCAPE)
        {
            std::cout << "GameScene exit" << std::endl;
            scene_manager.switch_scene(SceneManager::SceneType::Menu);
        }
    }
    void on_exit()
    {
    }
};

#endif // !_GAME_SCENE_H_