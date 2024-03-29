#pragma once

#include "include/Animation/Atlas.h"
#include "include/player/player.h"
#include "include/enemy/enemy.h"
#include "include/bullet/bullet.h"

void delete_game_resources()
{
    delete atlas_player_left;
    delete atlas_player_right;
    delete atlas_enemy_left;
    delete atlas_enemy_right;
}