#include <iostream>
using namespace std;
int main()
{
    /*int a = 1, b[3] = {'1'}, c = 1, d = 1;
    cout << &a << endl;
    cout << &b << endl;
    cout << &c << endl;
    cout << &d;

    int x = 2, y = 3;
    int a, b = 7, c = 5;
    a = !(b % 2);
    cout << a;
    a = !(b = c);
    cout << a;
    a = (a == 1);
    cout << a;
    cout << endl;

    int m = 1, n = -1;
    cout << m-- << ++n;
    printf("%d\n", (m & n));*/

    int a = 3, b = 4, c = 5, d;
    d = !(a + b) + c - 1 && b + c / 2;
    cout << d;
    system("pause");
    return 0;
}