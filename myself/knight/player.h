#ifndef _PLAYER_
#define _PLAYER_

#define SPEED 2;
#define P_G 10;

class Player
{
public:
    int x = 0, y = 200, air_time = 1, c = 0;
    Player() {}

    void draw(IMAGE *player)
    {
        putimage(x, y, player);
    }

    void move(IMAGE *player_l, IMAGE *player_r, int *stl)
    {

        if (GetAsyncKeyState('A'))
        {
            x -= SPEED;
            *stl = 1;
        }
        else if (GetAsyncKeyState('D'))
        {
            x += SPEED;
            *stl = 2;
        }

        if (GetAsyncKeyState(VK_SPACE))
        {
            c = 20;
        }

        if (*stl == 1)
            putimage(x, y, player_l);
        else
            putimage(x, y, player_r);

        y += 2 * air_time - c;

        Sleep(5);
        if (y >= 600)
        {
            y = 600;
            air_time = 0;
            c = 0;
        }
        else
        {
            air_time++;
        }
    }

    void attack(int stl)
    {
        if (GetAsyncKeyState('J'))
        {
            if (stl == 2)
            {
                IMAGE ar_p;
                loadimage(&ar_p, _T("./picture/attack/attack_r.png"), 70, 50);
                putimage(x + 20, y, &ar_p);
            }
            else if (stl == 1)
            {
                IMAGE al_p;
                loadimage(&al_p, _T("./picture/attack/attack_l.png"), 70, 50);
                putimage(x - 40, y, &al_p);
            }
            else if (GetAsyncKeyState('W'))
            {
                IMAGE au_p;
                loadimage(&au_p, _T("./picture/attack/attack_u.png"), 70, 90);
                putimage(x, y - 20, &au_p);
            }
            else if (GetAsyncKeyState('S'))
            {
                IMAGE ad_p;
                loadimage(&ad_p, _T("./picture/attack/attack_d.png"), 70, 90);
                putimage(x, y + 20, &ad_p);
            }
            else
            {
            }
        }
    }
};
#endif