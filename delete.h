#pragma once

#include "include/player/player.h"
#include "include/enemy/enemy.h"
#include "include/bullet/bullet.h"

#include "include/Animation/util.h"
#include "include/Animation/Atlas.h"
#include "include/Animation/Animation.h"

#include "include/scene/scene.h"
#include "include/scene/scene_manager.h"
#include "include/scene/menu_scene.h"
#include "include/scene/game_scene.h"
#include "include/scene/gameover_scene.h"

void delete_game_resources()
{

    delete menu_scene;
    delete game_scene;
    delete gameover_scene;
}