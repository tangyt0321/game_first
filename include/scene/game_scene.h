#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "scene.h"

class GameScene : public Scene
{
public:
    GameScene() = default;
    ~GameScene() = default;

    virtual void on_enter()
    {
        std::cout << "GameScene enter" << std::endl;
    }
    virtual void on_update()
    {
        std::cout << "GameScene update" << std::endl;
    }
    virtual void on_draw()
    {
        std::cout << "GameScene draw" << std::endl;
    }
    virtual void on_input(const ExMessage &msg)
    {
    }
    virtual void on_exit()
    {
    }
};

#endif // !_GAME_SCENE_H_