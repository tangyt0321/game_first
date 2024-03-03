#include <iostream>
using namespace std;

int main()
{
    int p1, p2, p3, p4, p5;
    for (int a = 0; a <= 1; a++)
        for (int b = 0; b <= 1; b++)
            for (int c = 0; c <= 1; c++)
                for (int d = 0; d <= 1; d++)
                    for (int e = 0; e <= 1; e++)
                    {
                        p1 = ((b + c + d + e) == 1) == a;
                        p2 = ((a + c + d + e) == 4) == b;
                        p3 = ((b + d + e) == 1) == c;
                        p4 = ((a + b + c + e) == 0) == d;
                        p5 = (c == e) == e;
                        if (p1 && p2 && p3 && p4 && p5)
                        {
                            cout << a << b << c << d << e;
                            break;
                        }
                    }
    system("pause");
    return 0;
}