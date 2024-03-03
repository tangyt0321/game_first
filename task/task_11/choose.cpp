#include <iostream>
using namespace std;
#include <cstring>

void fun(char *s)
{
    char a[100];
    int i = 0, j = 0;
    for (; i < 100, j < 100; i++, j++)
    {
        *(a + i) = *(s + j);
        if (j % 2 != 0)
        {
            i++;
            *(a + i) = ' ';
        }
    }
    *(a + i) = '\0';
    strcpy(s, a);
}

int main()
{
    char s[100];
    cout << "输入：";
    cin >> s;
    fun(s);
    cout << "输出：" << s;
    return 0;
}