#include <iostream>
using namespace std;

struct stu
{
    int name;
    int jug = 1; // 1=ture,0=fause
};

void first(struct stu *p)
{
    p[0].jug = 1;
    int count = 0;
    for (int i = 1; i < 5; i++)
    {
        if (p[i].jug == 0)
            count++;
    }
    if (count == 3)
    {
        p[0].jug = 1;
    }
    else
        p[0].jug = 0;
}

void second(struct stu *p)
{
    p[1].jug = 1;
    for (int i = 0; i < 5; i++)
    {
        if (i == 1)
            continue;
        if (p[i].jug != -1)
        {
            p[1].jug = 0;
            break;
        }
    }
}

void third(struct stu *p)
{
    p[2].jug = 1;
    int count = 0;
    for (int i = 1; i < 5; i++)
    {
        if (i == 2)
            continue;
        if (p[i].jug == 0)
            count++;
    }
    if (p[0].jug == 1)
        p[2].jug = 0;
    else if (count == 1)
        p[2].jug = 1;
    else
        p[2].jug = 0;
}

void fourth(struct stu *p)
{
    p[3].jug = 1;
    int count = 0;
    for (int i = 1; i < 5; i++)
    {
        if (i == 3)
            continue;
        if (p[i].jug == 1)
            count++;
    }
    if (count == 4)
        p[3].jug = 1;
    else
        p[3].jug = 0;
}

void fifth(struct stu *p)
{
    p[4].jug = 1;
    if (p[4].jug == p[2].jug)
        p[4].jug = 1;
    else
        p[4].jug = 0;
}

int main()
{
    struct stu s[5];
    for (int i = 0; i < 100; i++)
    {
        first(s);
        second(s);
        third(s);
        fourth(s);
        fifth(s);
    }
    for (int i = 0; i < 5; i++)
    {
        cout << s[i].jug << endl;
    }
    system("pause");
    return 0;
}
