#ifndef _BULLET_H_
#define _BULLET_H_

#include <easyx.h>
#include <ctime>
#include <cmath>

extern int random_id;

class Bullet
{
public:
    POINT position = {0, 0};
    float x, y;   // 子弹位置
    float vx, vy; // 子弹速度

private:
    const float BULLET_SPEED = 30; // 子弹速度常量
    const int RADIUS = 5;          // 子弹半径常量
    const int SCATTER = 100;        // 子弹散射范围常量

public:
    Bullet(const Player &player, float targetX, float targetY)
    {
        const POINT &player_pos = player.GetPosition();
        position.x = player_pos.x + player.PLAYER_WIDTH / 2;
        position.y = player_pos.y + player.PLAYER_HEIGHT / 2;

        // 计算子弹朝向目标的初始速度
        srand(random_id);
        int dx = targetX - position.x + sin(rand() % 360) * SCATTER - SCATTER / 2;
        int dy = targetY - position.y + cos(rand() % 360) * SCATTER - SCATTER / 2;

        double distance = std::sqrt(dx * dx + dy * dy);
        if (distance >= 1)
        {
            vx = (int)(dx / distance * BULLET_SPEED);
            vy = (int)(dy / distance * BULLET_SPEED);
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
};

#endif