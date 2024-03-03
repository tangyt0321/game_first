#include <stdio.h>
#include <stdlib.h>
int at(char s[], char c)
{
    int i;
    for (i = 0; i < 12; i++)
    {
        printf("%c", s[i]);
        /*if (c == s[i])
        {
            return i + 1;
        }*/
    }
    return 0;
}
int main()
{
    int i;
    char a[11], x;
    printf("输入字符串:");
    for (i = 0; i < 12; i++)
    {
        scanf("%c", &a[i]);
    }
    printf("输入查询字符:");
    scanf("%c", &x); // 问题1
    printf("首次出现位置:%d", at(a, x));
    system("pause");
    return 0;
}