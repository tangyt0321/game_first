#pragma once

#include "enemy_boar.h"
#include "enemy_knight.h"

extern std::vector<Enemy *> enemy_list;

class EnemyManager
{
public:
    enum class EnemyType
    {
        Knight,
        boar,
    };

public:
    EnemyManager() = default;
    ~EnemyManager() = default;

    void add_enemy_boar()
    {
        enemy_list.push_back(new EnemyBoar());
    }

    void add_enemy_knight()
    {
        enemy_list.push_back(new EnemyKnight());
    }

private:
    Enemy *current_enemy = nullptr;
};