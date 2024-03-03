#include <iostream>
using namespace std;
#include <cmath>

int main()
{
    double x, dx, y, c;
    int b;
    cin >> b;
    dx = 1.0 / b;
    for (int i = 0; i < b; i++)
    {
        x = x + dx;
        y = x * x * x * dx;
        c = c + y;
    }
    cout << c;
    system("pause");
    return 0;
}