#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "scene.h"
#include "scene_manager.h"

#include <iostream>

extern SceneManager scene_manager;

class GameScene : public Scene
{
public:
    GameScene() = default;
    ~GameScene() = default;

    void on_enter()
    {
        std::cout << "GameScene enter" << std::endl;
    }

    void on_update()
    {
        std::cout << "GameScene update" << std::endl;
    }

    void on_draw()
    {
        std::cout << "GameScene draw" << std::endl;
    }

    void on_input(const ExMessage &msg)
    {
        if (msg.message == WM_KEYDOWN )
        {
            scene_manager.switch_scene(SceneManager::SceneType::Menu);
        } 
    }
    void on_exit()
    {
    }
};

#endif // !_GAME_SCENE_H_