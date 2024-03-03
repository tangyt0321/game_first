#include <bits/stdc++.h>
#include <graphics.h>
#include <conio.h>
#include <time.h>

#define PLAYER_SIZE 20
using namespace std;

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
    void move()
    {
        MOUSEMSG m = GetMouseMsg();
        if (m.uMsg == WM_MOUSEMOVE)
        {
            x = m.x;
            y = m.y;
        }

        // if (GetAsyncKeyState(VK_LEFT))
        // {
        //     x -= 5;
        // }
        // if (GetAsyncKeyState(VK_RIGHT))
        // {
        //     x += 5;
        // }
        // if (GetAsyncKeyState(VK_UP))
        // {
        //     y -= 5;
        // }
        // if (GetAsyncKeyState(VK_DOWN))
        // {
        //     y += 5;
        // }
    }
};

int main()
{
    initgraph(640, 480);
    srand(time(NULL));

    Player player;
    player.draw();
    int a = 2;
    while (a > 1)
    {
        // GetMouseMSG();
        // cleardevice();
        player.move();
        player.draw();

        //Sleep(120);
    }

    // while (!_kbhit())
    // {
    //     cleardevice();

    //     player.draw();

    //     Sleep(30);
    // }

    closegraph();
    return 0;
}