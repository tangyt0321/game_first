#pragma once

#include "enemy.h"
#include <vector>

class EnemyKnight : public Enemy {
public:
    EnemyKnight();
    ~EnemyKnight()=default;

    void update();
    void draw();
};