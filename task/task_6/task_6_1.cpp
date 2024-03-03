#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[20];
    cout << "输入一行字符串" << endl;
    gets(a);
    cout << "逆序输出的结果" << endl;
    for (int i = strlen(a) - 1; i >= 0; i--)
    {
        cout << a[i];
    }
    cout << endl;
    return 0;
}