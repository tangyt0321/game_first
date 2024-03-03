#include <stdio.h>
int main()
{
    int a;
    printf("input the number ");
    scanf("%d", &a);
    if (a < 0)
        a = -a;
    else if (a >= 5 && a < 20)
        a = 3 * a * a - 2 * a + 1;
    else if (a >= 20)
        a = a / 5;
    printf("%d", a);
    return 0;
}