#pragma once

#include "enemy.h"

class EnemyKnight : public Enemy {
public:
    EnemyKnight();
    ~EnemyKnight();

    void update();
    void draw();
};