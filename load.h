#pragma once

#include "include/Animation/Atlas.h"
#include"include/player/player.h"

void load_game_sources()
{
    const int PLAYER_WIDTH = 80;  // 玩家宽度
    const int PLAYER_HEIGHT = 80; // 玩家高度
    atlas_player_left = new Atlas(_T("resource/images/player/player_left_%d.png"), PLAYER_ANIM_NUM, PLAYER_WIDTH, PLAYER_HEIGHT);
    atlas_player_right = new Atlas(_T("resource/images/player/player_right_%d.png"), PLAYER_ANIM_NUM, PLAYER_WIDTH, PLAYER_HEIGHT);
}