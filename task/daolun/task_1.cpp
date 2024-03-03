#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

// jz = "进制"
// tnum = ten jz number
// xnum = x jz number

// 将十进制数转换为任意进制
// 参数 tnum 为十进制数，参数 jz 为目标进制
void x_change(int tnum, int jz)
{
    char xnum[100];
    int j = 0;
    for (; tnum >= jz; j++)
    {
        if (tnum % jz <= 9)
            xnum[j] = tnum % jz + '0';
        else
            xnum[j] = tnum % jz - 10 + 'A';
        tnum /= jz;
    }
    if (tnum <= 9)
        xnum[j] = tnum + '0';
    else
        xnum[j] = tnum - 10 + 'A';
    for (int i = j; i >= 0; i--)
    {
        cout << xnum[i];
    }
    cout << endl;
}

// 将输入的数转换为十进制
int ten_change(char num[], int jz)
{
    int tnum = 0, i, b;
    for (i = 0; i < strlen(num); i++)
    {
        if (num[i] >= 'a')
            b = num[i] - 'a' + 10;
        else if (num[i] >= 'A')
            b = num[i] - 'A' + 10;
        else
            b = num[i] - '0';
        tnum += b * pow(jz, strlen(num) - i - 1);
    }
    return tnum;
}

int main()
{
    char num[100];
    int jz1, jz2;
    cout << "输入要转换的数：";
    cin >> num;
    cout << "输入数的进制:";
    cin >> jz1;
    cout << "要转换的进制:";
    cin >> jz2;
    x_change(ten_change(num, jz1), jz2);
    system("pause");
    return 0;
}