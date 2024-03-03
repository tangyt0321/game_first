#include <iostream>
using namespace std;
#include <math.h>
int eat(int n, int m)
{
    n = (n + 1) * 2;
    m--;
    if (m == 0)
        return n;
    eat(n, m);
}

int main()
{
    int n, day = 9;
    cin >> n;
    cout << eat(n, day);
    return 0;
}