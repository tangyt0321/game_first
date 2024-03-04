#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <iostream>

#define ENEMY_SIZE 20
#define BULLET_SIZE 5
#define BULLET_SPEED 5
#define ENEMY_SPEED 3
#define PLAYER_SIZE 40

class Player
{
public:
    int x, y;
    Player() : x(getwidth() / 2 - PLAYER_SIZE / 2), y(getheight() - PLAYER_SIZE - 10) {}
    void draw()
    {
        setfillcolor(WHITE);
        solidrectangle(x, y, x + PLAYER_SIZE, y + PLAYER_SIZE);
    }
};

class Enemy
{
public:
    int x, y;
    Enemy() : x(rand() % (getwidth() - ENEMY_SIZE)), y(-ENEMY_SIZE) {}
    void draw()
    {
        setfillcolor(RED);
        solidrectangle(x, y, x + ENEMY_SIZE, y + ENEMY_SIZE);
    }
    void move()
    {
        y += ENEMY_SPEED;
        if (y > getheight())
        {
            x = rand() % (getwidth() - ENEMY_SIZE);
            y = -ENEMY_SIZE;
        }
    }
};

class Bullet
{
public:
    int x, y;
    // 构造函数，接受玩家飞机的x和y坐标
    Bullet(int px, int py) : x(px + PLAYER_SIZE / 2), y(py - BULLET_SIZE) {}
    void draw()
    {
        setfillcolor(YELLOW);
        solidcircle(x, y, BULLET_SIZE);
    }
    void move()
    {
        y -= BULLET_SPEED;
        // 如果子弹移出屏幕，则重置其位置
        if (y < -BULLET_SIZE)
        {
            x = -1; // 用一个无效值标记子弹，以便在检查碰撞时忽略它
            y = -1;
        }
    }
};

int main()
{
    initgraph(640, 480);
    srand(time(NULL));
    setbkcolor(WHITE);

    Player player;
    Enemy enemy;
    Bullet bullet(0, 0);

    while (!_kbhit())
    {
        cleardevice();

        player.draw();
        enemy.draw();

        if (_kbhit())
        {
            if (_getch() == ' ')
            {
                // 在玩家飞机位置创建子弹对象
                bullet = Bullet(player.x, player.y);
            }
        }

        if (bullet.x != -1)
        { // 检查子弹是否仍然有效
            bullet.draw();
            bullet.move();

            // 检查子弹和敌机是否碰撞
            if (abs(bullet.x - enemy.x) < (ENEMY_SIZE / 2 + BULLET_SIZE) &&
                abs(bullet.y - enemy.y) < (ENEMY_SIZE / 2 + BULLET_SIZE))
            {
                // 击中敌机，重置敌机和子弹的位置
                enemy.x = rand() % (getwidth() - ENEMY_SIZE);
                enemy.y = -ENEMY_SIZE;
                bullet.x = -1;
                bullet.y = -1;
            }
        }

        enemy.move();

        Sleep(30);
    }

    closegraph();
    return 0;
}