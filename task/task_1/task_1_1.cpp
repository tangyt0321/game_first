#define pi 3.14159
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float x, y, z;
    printf("Input x:");
    scanf("%f", &x);
    printf("Input y:");
    scanf("%f", &y);
    z = (log10(x * x + 3) + pi / 2 * cos(2 * pi / 9)) / y;
    printf("the result is:%f\n", z);
    system("pause");
    return 0;
}
