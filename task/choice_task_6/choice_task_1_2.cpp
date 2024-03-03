#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>
int main()
{
    int n = 0, num[26], y;
    for (int i = 0; i < 26; i++)
    {
        num[i] = 0;
    }
    char a[100], yy;
    cout << "Enter a string: ";
    gets(a);

    for (int i = 0; i < strlen(a); i++)
    {
        y = *(int *)&a[i];
        if (a[i] >= 'a' && a[i] <= 'z')
            num[a[i] - 'a']++;
        else if (a[i] >= 'A' && a[i] <= 'Z')
            num[a[i] - 'A']++;
    }

    cout << "统计结果" << endl;

    for (int i = 65; i < 91; i++)
    {
        if (num[i - 65] != 0)
        {
            yy = i;
            cout << yy << "=" << num[i - 65] << " ";
            n = n + 1;
        }
    }

    cout << endl;
    cout << "共有" << n << "个字符种类" << endl;
    system("pause");
    return 0;
}