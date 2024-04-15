#pragma once

#include "include/player/player.h"
#include "include/bullet/bullet.h"

#include "include/enemy/enemy_boar.h"
#include "include/enemy/enemy_knight.h"
#include "include/enemy/enemy_manager.h"

#include "include/Animation/util.h"
#include "include/Animation/Atlas.h"
#include "include/Animation/Animation.h"

#include "include/scene/scene.h"
#include "include/scene/scene_manager.h"
#include "include/scene/menu_scene.h"
#include "include/scene/game_scene.h"
#include "include/scene/upgrade_scene.h"
#include "include/scene/gameover_scene.h"

Scene *menu_scene = nullptr;
Scene *game_scene = nullptr;
Scene *gameover_scene = nullptr;
Scene *upgrade_scene = nullptr;

IMAGE img_menu_background;   // 菜单背景
IMAGE img_background;        // 游戏背景
IMAGE img_shadow;            // 玩家阴影
IMAGE img_enemy_boar_shadow; // 野猪敌人阴影
// IMAGE img_enemy_knight_shadow; // 骑士敌人阴影
Atlas atlas_player_left;      // 玩家左侧动画
Atlas atlas_player_right;     // 玩家右侧动画
Atlas atlas_enemy_boar_left;  // 野猪敌人左侧动画
Atlas atlas_enemy_boar_right; // 野猪敌人右侧动画

Player player;
std::vector<Enemy *> enemy_list;
std::vector<Bullet *> bullet_list;

// 翻转图像
void flip_image_vertically(Atlas &src, Atlas &dst)
{
    dst.clear();
    for (int i = 0; i < src.get_size(); i++)
    {
        IMAGE img_flip;
        FlipImageVertically(src.get_img(i), &img_flip);
        dst.add_img(img_flip);
    }
}

// 加载游戏资源
void load_game_sources()
{
    // 加载菜单背景
    loadimage(&img_menu_background, _T("resource/images/bkg/menu_bkg.png"));
    // 加载玩家动画
    loadimage(&img_shadow, _T("resource/images/player/shadow_player.png"), 50, 30);
    atlas_player_right.Load_from_file(_T("resource/images/player/player_right_%d.png"), PLAYER_ANIM_NUM, PLAYER_WIDTH, PLAYER_HEIGHT);
    flip_image_vertically(atlas_player_right, atlas_player_left);
    // 加载敌人动画
    loadimage(&img_enemy_boar_shadow, _T("resource/images/enemy/shadow_enemy.png"), 50, 30);
    atlas_enemy_boar_right.Load_from_file(_T("resource/images/enemy/boar_right_%d.png"), BOAR_ANIM_NUM, BOAR_WIDTH, BOAR_HEIGHT);
    flip_image_vertically(atlas_enemy_boar_right, atlas_enemy_boar_left);
    // 加载游戏背景
    loadimage(&img_background, _T("resource/images/bkg/bkg.png"));
}