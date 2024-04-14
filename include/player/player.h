#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <easyx.h>
#include "../Animation/Animation.h"

extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;


extern Atlas atlas_player_left;
extern Atlas atlas_player_right;
extern IMAGE img_shadow;

const int PLAYER_ANIM_NUM = 6;
const int PLAYER_WIDTH = 80;  // 玩家宽度
const int PLAYER_HEIGHT = 80; // 玩家高度

class Player
{
public:
    const int SHADOW_PLAYER_WIDTH = 50; // 阴影宽度
    const int PLAYER_WIDTH = 80;        // 玩家宽度
    const int PLAYER_HEIGHT = 80;       // 玩家高度
    const int PLAYER_SPEED = 7;
    POINT position = {500, 500};
    size_t HP = 5;
    bool alive = true;

private:
    Animation anim_left;
    Animation anim_right;
    bool is_move_up = false;
    bool is_move_down = false;
    bool is_move_left = false;
    bool is_move_right = false;



public:
    Player()
    {
        anim_left.set_atlas(&atlas_player_left);
        anim_left.set_interval(45);
        anim_right.set_atlas(&atlas_player_right);
        anim_right.set_interval(45);
    }
    ~Player() = default;

    void ProcessEvent(const ExMessage &msg)
    {
        switch (msg.message)
        {
        case WM_KEYDOWN:
            switch (msg.vkcode)
            {
            case 'W':
                is_move_up = true;
                break;
            case 'S':
                is_move_down = true;
                break;
            case 'A':
                is_move_left = true;
                break;
            case 'D':
                is_move_right = true;
                break;
            }
            break;
        case WM_KEYUP:
            switch (msg.vkcode)
            {
            case 'W':
                is_move_up = false;
                break;
            case 'S':
                is_move_down = false;
                break;
            case 'A':
                is_move_left = false;
                break;
            case 'D':
                is_move_right = false;
                break;
            }
            break;
        }
    }

    void Move()
    {
        int dir_x = is_move_right - is_move_left;
        int dir_y = is_move_down - is_move_up;
        double len_dir = sqrt(dir_x * dir_x + dir_y * dir_y);
        if (len_dir != 0)
        {
            double normalized_x = dir_x / len_dir;
            double normalized_y = dir_y / len_dir;
            position.x += (int)(normalized_x * PLAYER_SPEED);
            position.y += (int)(normalized_y * PLAYER_SPEED);
        }

        if (position.x < 0)
            position.x = 0;
        if (position.y < 0)
            position.y = 0;
        if (position.x > WINDOW_WIDTH - PLAYER_WIDTH)
            position.x = WINDOW_WIDTH - PLAYER_WIDTH;
        if (position.y > WINDOW_HEIGHT - PLAYER_HEIGHT)
            position.y = WINDOW_HEIGHT - PLAYER_HEIGHT;
    }

    void Draw(int delta)
    {
        int pos_shadow_x = position.x + (PLAYER_WIDTH / 2 - SHADOW_PLAYER_WIDTH / 2);
        int pos_shadow_y = position.y + (PLAYER_HEIGHT / 2 + 30);
        putimage_alpha(pos_shadow_x, pos_shadow_y, &img_shadow);
        static bool facing_left = false;
        int dir_x = is_move_right - is_move_left;
        if (dir_x < 0)
            facing_left = true;
        else if (dir_x > 0)
            facing_left = false;

        if (facing_left)
        {
            anim_left.on_update(delta);
            anim_left.on_draw(position.x, position.y);
        }
        else
        {
            anim_right.on_update(delta);
            anim_right.on_draw(position.x, position.y);
        }
    }

    void hurt()
    {
        HP--;
        if (HP <= 0)
            alive = false;
    }

    bool isAlive()
    {
        return alive;
    }

    const POINT &GetPosition() const
    {
        return position;
    }
};

#endif