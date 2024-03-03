#include <iostream>
using namespace std;
#include <stdlib.h>

void swap(int *a, int *b, int m);

int main()
{
    int m;
    cout << "输入数组元素的个数m:" << endl;
    cin >> m;

    int arr1[m], *a = &arr1[0];
    int arr2[m], *b = &arr2[0];

    printf("输入数组的%d个元素值:\n", m);
    for (int i = 0; i < m; i++)
    {
        cin >> *(a + i);
    }

    swap(a, b, m);

    cout << "数组逆置后的结果:" << endl;
    for (int i = 0; i < m; i++)
    {
        cout << *(a + i) << " ";
    }
    system("pause");
    return 0;
}

void swap(int *a, int *b, int m)
{
    for (int i = 0, j = m - 1; i < m, j >= 0; i++, j--)
    {
        *(b + i) = *(a + j);
    }
    for (int i = 0; i < m; i++)
    {
        *(a + i) = *(b + i);
    }
}