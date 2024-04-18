#pragma once

#include "Vector2.h"
#include "timer/timer.h"

extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;
extern int PLAYER_WIDTH;
extern int PLAYER_HEIGHT;

class Camera
{
public:
    Camera()
    {
        timer_shake.set_one_shot(true);
        timer_shake.set_callback([&]()
                                 {  
            is_shaking = false;
            reset_position(); });
    }
    ~Camera() = default;

    const Vector2 &get_position() const
    {
        return position;
    }

    void set_position(const Vector2 &pos)
    {
        position = pos;
    }

    void reset_position()
    {
        position = Vector2(0.0f, 0.0f);
    }

    void shake(float strength, int duration)
    {
        is_shaking = true;
        shake_strength = strength;
        timer_shake.set_wait_time(duration);
        timer_shake.restart();
    }

    void on_update(int delta, float target_x = 0.0f, float target_y = 0.0f) // 这里的target_x, target_y是为了让摄像机跟随玩家移动而设置的
    {
        // 跟随玩家移动
        if (target_x != 0.0f || target_y != 0.0f)
        {
            position.x += (target_x - position.x - WINDOW_WIDTH / 2 + PLAYER_WIDTH / 2) * 0.1f;
            position.y += (target_y - position.y - WINDOW_HEIGHT / 2 + PLAYER_HEIGHT / 2) * 0.1f;
        }

        // 震动更新
        timer_shake.update(delta);
        if (is_shaking)
        {
            position.x = (-50 + rand() % 100) / 50.0f * shake_strength;
            position.y = (-50 + rand() % 100) / 50.0f * shake_strength;
        }
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
