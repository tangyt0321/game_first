#include <iostream>
using namespace std;
#include <time.h>
#include <stdlib.h>
int main()
{
    int arr[10];
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        *(arr + i) = rand() % 100;
        cout << *(arr + i) << " ";
    }
    cout << endl;
    for (int j = 0; j < 10; j = j + 2)
    {
        cout << *(arr + j + 1) << " ";
        cout << *(arr + j) << " ";
    }
    return 0;
}