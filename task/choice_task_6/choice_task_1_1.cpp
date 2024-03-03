#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>

int main()
{
    int m, n;

    cout << "Enter n:";
    cin >> n;
    cout << "Enter m:";
    cin >> m;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    int x = 1;

    for (; n > 1; n--)
    {
        x = (x + m - 1) % n;
        if (x == 0)
            x = x + n;
        cout << "the " << a[x - 1] << " is lose" << endl;
        for (int i = x; i < n; i++)
        {
            a[i - 1] = a[i];
        }
        int new_size = n - 1;
    }

    cout << "the winner is:" << a[0] << endl;
    system("pause");
    return 0;
}