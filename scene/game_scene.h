#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "scene.h"

class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene *createScene();

    virtual bool init();

    CREATE_FUNC(GameScene);
};

#endif // !_GAME_SCENE_H_