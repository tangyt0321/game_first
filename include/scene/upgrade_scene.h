#pragma once

#include "scene.h"
#include "scene_manager.h"

#include <iostream>

extern SceneManager scene_manager;
extern bool is_game_start;

class UpgradeScene : public Scene
{
public:
    UpgradeScene();
    ~UpgradeScene();
};
