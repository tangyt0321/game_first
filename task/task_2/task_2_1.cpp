#include <stdio.h>
int main()
{
    float a, b, c, d, e;
    printf("输入成绩");
    scanf("%f%f%f%f", &a, &b, &c, &d);
    e = (a + b + c + d) / 4;
    printf("平均分是：%3.1f\n", e);
    return 0;
}