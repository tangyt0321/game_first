#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>
int maxv(int *v)
{
    int max = v[0], i;
    for (int i = 0; i < 5; i++)
    {
        if (*(v + i) > max)
        {
            max = *(v + i);
        }
    }
    return max;
}

int main()
{
    int v[5];
    cout << "Introduceti 5 numere: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> *(v + i);
    }
    cout << "Maximul este: " << maxv(v) << endl;
    system("pause");
    return 0;
}