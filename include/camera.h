#pragma once

#include "Vector2.h"
#include "timer.h"


extern Player player;

class Camera
{
public:
    Camera() = default;
    ~Camera() = default;

    const Vector2 &get_position() const { return position; }
    void set_position(const Vector2 &pos) { position = pos; }
    void reset_position() { position = Vector2(0.0f, 0.0f); }

    void on_update(int delta)
    {
        // Vector2 player_pos = player.GetPosition();
        // position.x = player_pos.x - 400.0f;
        // position.y = player_pos.y - 300.0f;
        
        // if (is_shaking)
        // {
        //     if (timer_shake.elapsed_time() < 0.1f)
        //     {
        //         position.x += (rand() % 200 - 100) * shake_strength;
        //         position.y += (rand() % 200 - 100) * shake_strength;
        //     }
        //     else
        //     {
        //         is_shaking = false;
        //         timer_shake.reset();
        //     }
        // }
    }

    // void shake(float strength)
    // {
    //     timer_shake.start();
    //     is_shaking = true;
    //     shake_strength = strength;
    // }

private:
    Vector2 position;        // 摄像机位置
    Timer timer_shake;       // 震动计时器
    bool is_shaking = false; // 是否正在震动
    float shake_strength;    // 震动强度

public:
};
