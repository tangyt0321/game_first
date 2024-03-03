#include <iostream>
using namespace std;
#include <math.h>
int fact(float n)
{
    if (n > 0)
        n = 1;
    else
        n = 0;
    return n;
}

char f(float a, float b)
{
    char f;
    if (fact(a) == fact(b))
        f = 'Y';
    else
        f = 'N';
    return f;
}

int main()
{
    float a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << f(a, b);
    return 0;
}