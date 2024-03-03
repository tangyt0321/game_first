#include <iostream>
using namespace std;
#include <time.h>
#include <stdlib.h>

int main()
{
    double x, y, b = 0;
    long i;
    srand(time(NULL));
    for (i = 0; i < 1000000; i++)
    {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        if (y < x * x * x)
            b++;
    }
    cout << b / i << endl;
    system("pause");
    return 0;
}
