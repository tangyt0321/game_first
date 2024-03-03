#include <stdio.h>
#include <stdlib.h>

void fun(int *p1, int *p2)
{
    int *p;
    *p = *p1;
    *p1 = *p2;
    *p2 = *p;
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    fun(&a, &b);
    printf("%d %d\n", a, b);
    system("pause");
    return 0;
}