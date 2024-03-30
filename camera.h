#pragma once

#inlcude "vector2.h"
#include "timer.h"

class Camera
{
public:
    Camera();
    ~Camera();

private:
    Vector2 position;        // 摄像机位置
    Timer timer_shake;       // 震动计时器
    bool is_shaking = false; // 是否正在震动
    float shake_strength;    // 震动强度

public:
    void update(float delta_time);
    void shake(float strength);
    void stop_shake();
    void set_position(const Vector2 &pos);
    const Vector2 &get_position() const;
};
