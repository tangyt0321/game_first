#include <iostream>
using namespace std;
#include <math.h>
int digit(int x, int m)
{
    x = x / pow(10, m - 1);
    return x % 10;
}

int main()
{
    int x, m;
    cout << "Enter the number and the number of digits:" << endl;
    cin >> x >> m;
    printf("digit<%d,%d>=%d", x, m, digit(x, m));
    return 0;
}