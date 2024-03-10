#ifndef _BULLET_H_
#define _BULLET_H_

#include <easyx.h>

class Bullet
{
public:
    POINT positon = {0, 0};

public:
    Bullet() = default;
    ~Bullet() = default;

    void Draw() const
    {
        setfillcolor(RGB(255, 155, 50));
        setlinecolor(RGB(255, 75, 10));
        fillcircle(position.x, position.y, 3);
    }

private:
    const int RADIUS = 10;
};

#endif