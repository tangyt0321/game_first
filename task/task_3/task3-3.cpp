#include <stdio.h>
int main()
{
    float y, x, z;
    int n, j = 0;
    printf("Enter the number: ");
    scanf("%d", &n);
    printf("1");
    for (j = 2; j <= n; j++)
    {
        x = j;
        z = (x - 1) / x;
        if (j % 2 == 0)
        {
            y = y - z;
            printf("-%d/%d", j - 1, j);
        }
        else
        {
            y = y + z;
            printf("+%d/%d", j - 1, j);
        }
    }
    printf("=%f", 1 + y);
    return 0;
}
