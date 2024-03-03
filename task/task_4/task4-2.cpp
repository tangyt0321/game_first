#include <stdio.h>
int main()
{
    int n, m, i, j, a = 0;
    printf("input the first number:");
    scanf("%d", &n);
    printf("the end number is:");
    scanf("%d", &m);
    for (i = n; i <= m; i++)
    {
        for (j = 2; j < i - 1; j++)
        {
            if (i % j == 0)
                break;
            if (j == i - 2)
            {
                printf("%d  ", i);
                a = a + 1;
                if (a % 5 == 0)
                    printf("\n");
            }
        }
    }
}
