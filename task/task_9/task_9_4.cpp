#include <iostream>
using namespace std;

int select(int *p, int *q);

int main()
{
    cout << "输入十个数组元素" << endl;
    int arr1[10], *a = &arr1[0];
    int arr2[10], *b = &arr2[0];
    int c;
    for (int i = 0; i < 10; i++)
    {
        cin >> *(a + i);
    }
    cout << endl
         << "挑选后的数组元素" << endl;
    c = select(a, b);
    for (int i = 0; i < c; i++)
    {
        cout << *(b + i) << " ";
    }
    return 0;
}

int select(int *p, int *q)
{
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        if (*(p + i) % 2 != 0)
        {
            *(q + count) = *(p + i);
            count++;
        }
    }
    return count;
}