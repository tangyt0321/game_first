#pragma once

#include <easyx.h>
#include <time.h>
#include "../Animation/Animation.h"
#include "../bullet/bullet.h"

extern Player player;

class Enemy
{
public:
    POINT position = {0, 0};

public:
    Enemy()
    {
    }
    ~Enemy() = default;

    virtual bool CheckPlayerConllision(const Player &player) { return false; }
    virtual bool CheckBulletConllision(const Bullet *bullet) { return false; }
    virtual void hurt() {}
    virtual bool isAlive() { return true; }
    virtual void Move(const Player &player) {}
    virtual void Draw(int delta) {}

private:
};