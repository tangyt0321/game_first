#ifndef _BULLET_H_
#define _BULLET_H_

#include <easyx.h>

class Bullet
{
public:
    POINT position = {0, 0};
    float x, y;   // 子弹位置
    float vx, vy; // 子弹速度

public:
    Bullet(const Player &player, float targetX, float targetY)
    {
        const POINT &player_pos = player.GetPosition();
        position.x = player_pos.x + player.PLAYER_WIDTH / 2;
        position.y = player_pos.y + player.PLAYER_HEIGHT / 2;

        // 计算子弹朝向目标的初始速度
        int dx = targetX - position.x;
        int dy = targetY - position.y;
        double distance = std::sqrt(dx * dx + dy * dy);
        if (distance >= 1)
        {
            vx += (int)(dx / distance * BULLET_SPEED);
            vy += (int)(dy / distance * BULLET_SPEED);
        }
    }
    ~Bullet() = default;

    void Draw() const
    {
        setfillcolor(RGB(255, 155, 50));
        setlinecolor(RGB(255, 75, 10));
        fillcircle(position.x, position.y, RADIUS);
    }

    void Move()
    {
        // 更新子弹位置
        position.x += vx;
        position.y += vy;
    }

private:
    const float BULLET_SPEED = 30; // 子弹速度常量
    const int RADIUS = 2;
};

#endif