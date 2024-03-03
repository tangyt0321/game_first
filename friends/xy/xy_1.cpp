#include <iostream>
#include <string.h>
using namespace std;
void fun(char *s)
{
    // char *p = s;  没意义，直接用s即可
    int i, j;
    for (i = 0; *(s + i) != '\0'; i++)
    {
        // if (i % 2 != 0)  这只能一位一空格
        if (i % 3 == 2)
        {
            // for (j = i + 1; *(p + j) != '\0'; j++)   所有位向后推，循环应从后向前执行
            for (j = strlen(s); j > i + 1; j--)
            {
                *(s + j + 1) = *(s + j);
            }
            *(s + i) = ' '; // 移出循环
            // p = p + i + 1;
            // break;    无意义
        }
    }
}

int main()
{
    char a[80], *p1 = a;
    gets(a);
    fun(a);
    for (p1 = a; p1 < a + strlen(a);)
    {
        cout << *p1++;
    }
    return 0;
}