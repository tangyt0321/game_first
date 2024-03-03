#include <iostream>
using namespace std;
#include <math.h>

long c(int x)
{
    int c = 1;
    for (int i = 1; i < x + 1; i++)
    {
        c = c * i;
    }
    return c;
}

int main()
{
    int m, n, y;
    cout << "enter m and n" << endl;
    cin >> m >> n;
    y = c(m) / c(n) / c(m - n);
    cout << y << endl;
    return 0;
}