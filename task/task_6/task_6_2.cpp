#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>
int main()
{
    int i;
    char a[] = {"This is a c/c++ program."}, x;
    cout << "字符串为:" << a << endl;
    cout << "输入字符:";
    cin >> x;
    for (i = 0; i < strlen(a) - 1; i++)
    {
        if (x == a[i])
        {
            cout << "起始位置" << i + 1 << endl;
            system("pause");
        }
    }
    cout << "Not found" << endl;
    system("pause");
    return 0;
}