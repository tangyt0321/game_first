#include <stdio.h>
int main()
{
    int a, b, output;
    printf("Enter two numbers:");
    scanf("%d%d", &a, &b);
    output = a * b;
    printf("%d*%d=%d\n", a, b, output);
}
