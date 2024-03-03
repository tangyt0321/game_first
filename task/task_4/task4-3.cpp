#include <stdio.h>
int main()
{
    int n, i, j;
    printf("input the number:");
    scanf("%d", &n);
    for (i = 1; i < n; i++)
    {
        for (j = 1; j <= i + 1; j++)
        {
            printf("%d ", j);
        }
        for (j = i; j > 1; j--)
        {
            printf("%d ", j);
        }
    }
    printf("1\n");
    return 0;
}
