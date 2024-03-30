#pragma once

#include "include/player/player.h"
#include "include/enemy/enemy.h"
#include "include/bullet/bullet.h"

#include "include/Animation/FlipImageVertically.h"
#include "include/Animation/Atlas.h"
#include "include/Animation/Animation.h"

#include "include/scene/scene.h"
#include "include/scene/scene_manager.h"
#include "include/scene/menu_scene.h"
#include "include/scene/game_scene.h"
#include "include/scene/gameover_scene.h"

IMAGE img_menu_background;

Scene *menu_scene = nullptr;
Scene *game_scene = nullptr;
Scene *gameover_scene = nullptr;

Atlas atlas_player_left;
Atlas atlas_player_right;
Atlas atlas_enemy_left;
Atlas atlas_enemy_right;

void flip_image_vertically(Atlas &src, Atlas &dst)
{
    dst.clear();
    for (int i = 0; i < src.get_size(); ++i)
    {
        IMAGE img_flip;
        FlipImageVertically(src.get_img(i), &img_flip);
        dst.add_img(img_flip);
    }
}

void load_game_sources()
{
    const int PLAYER_WIDTH = 80;  // 玩家宽度
    const int PLAYER_HEIGHT = 80; // 玩家高度
    loadimage(&img_menu_background, _T("resource/images/menu/menu_background.png"));

    atlas_player_left.Load_from_file(_T("resource/images/player/player_left_%d.png"), PLAYER_ANIM_NUM, PLAYER_WIDTH, PLAYER_HEIGHT);
    flip_image_vertically(atlas_player_left, atlas_player_right);
    atlas_enemy_left.Load_from_file(_T("resource/images/enemy/boar_left_%d.png"), BOAR_ANIM_NUM, BOAR_WIDTH, BOAR_HEIGHT);
    flip_image_vertically(atlas_enemy_left, atlas_enemy_right);

    // atlas_player_left = new Atlas(_T("resource/images/player/player_left_%d.png"), PLAYER_ANIM_NUM, PLAYER_WIDTH, PLAYER_HEIGHT);
    // atlas_player_right = new Atlas(_T("resource/images/player/player_right_%d.png"), PLAYER_ANIM_NUM, PLAYER_WIDTH, PLAYER_HEIGHT);

    const int BOAR_WIDTH = 80;  // 敌人宽度
    const int BOAR_HEIGHT = 80; // 敌人高度
    // atlas_enemy_left = new Atlas(_T("resource/images/enemy/boar_left_%d.png"), BOAR_ANIM_NUM, BOAR_WIDTH, BOAR_HEIGHT);
    // atlas_enemy_right = new Atlas(_T("resource/images/enemy/boar_right_%d.png"), BOAR_ANIM_NUM, BOAR_WIDTH, BOAR_HEIGHT);
}