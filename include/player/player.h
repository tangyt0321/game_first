#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <easyx.h>
#include "../Animation/Animation.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define PLAYER_ANIM_NUM 6

class Player
{
public:
    const int PLAYER_WIDTH = 80;        // 玩家宽度
    const int PLAYER_HEIGHT = 80;       // 玩家高度
    const int SHADOW_PLAYER_WIDTH = 50; // 阴影宽度
    const int PLAYER_SPEED = 7;
    POINT position = {500, 500};

private:
    IMAGE img_shadow;
    Animation *anim_left;
    Animation *anim_right;

    bool is_move_up = false;
    bool is_move_down = false;
    bool is_move_left = false;
    bool is_move_right = false;

    bool alive = true;

public:
    Player()
    {
        loadimage(&img_shadow, _T("resource/images/player/shadow_player.png"), 50, 30);
        anim_left = new Animation(atlas_player_left, 45);
        anim_right = new Animation(atlas_player_right, 45);
    }
    ~Player()
    {
        delete anim_left;
        delete anim_right;
    }

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
            anim_left->Play(position.x, position.y, delta);
        else
            anim_right->Play(position.x, position.y, delta);
    }

    void hurt()
    {
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