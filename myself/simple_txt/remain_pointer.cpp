#include <iostream>
using namespace std;
#include <stdlib.h>

void min(int a[], int n, int *x, int *y);

int main()
{
    int n = 10, a[n];
    int x, y;
    cout << "Enter the string: " << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    min(a, n, &x, &y);
    cout << x << endl;
    cout << y;
    cin.get();
    cin.get();
    return 0;
}

void min(int a[], int n, int *x, int *y)
{
    int min, k;
    min = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            k = i;
        }
    }
    *x = min;
    *y = k;
}