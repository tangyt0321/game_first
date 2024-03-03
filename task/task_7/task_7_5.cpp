#include <iostream>
using namespace std;
#include <stdlib.h>

int min(int a[], int n);
int nn(int a[], int n);

int main()
{
    int n = 10, a[n];
    cout << "Enter the string: " << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << min(a, n) << endl;
    cout << nn(a, n);
    cin.get();
    cin.get();
    return 0;
}

int min(int a[], int n)
{
    int min;
    min = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

int nn(int a[], int n)
{
    int min, k;
    min = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)
            k = i;
    }
    return k;
}