#include <iostream>
using namespace std;
#include <stdlib.h>
int main()
{
    int v[5];
    for (int j = 0; j < 5; j++)
        cin >> v[j];
    int *p;
    for (p = v; p != v + 5; p++)
        *p = 0;
    for (int i = 0; i < 5; i++)
        cout << v[i];
    cout << endl;
    system("pause");
    return 0;
}