#include <iostream>
using namespace std;

void insert(int b[], int m)
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        if (m < b[i])
        {
            for (j = 10; j > i; j--)
            {
                b[j] = b[j - 1];
            }
            b[i] = m;
            break;
        }
    }
}

int main()
{
    int a[11], i, m;
    cout << "输入10个数组元素  ";
    for (i = 0; i < 10; i++)
        cin >> a[i];
    cout << "输入插入的值  ";
    cin >> m;
    insert(a, m);
    cout << "插入后的数组  ";
    for (i = 0; i < 11; i++)
        cout << a[i] << " ";
    cout << endl;
    cin.get();
    cin.get();
    return 0;
}