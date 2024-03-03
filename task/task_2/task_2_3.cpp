#include <stdio.h>
int main()
{
    char a;
    printf("请输入一个字符：");
    scanf("%c", &a);
    if (a > 47 && a < 58)
        printf("%c是个数字", a);
    else if (a > 64 && a < 91 || a > 96 && a < 123)
        printf("%c是个字母", a);
    else
        printf("%c是个其他", a);
    return 0;
}