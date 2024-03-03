#include <stdio.h>
int main()
{
    int a = 0;
    printf("the outcome is:\n");
    for (int i = 100; i <= 999; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (i % 10 == j && (i / 100) == j && (i / 10) % 10 % 2 == (2 && j))
            {
                printf("%d ", i);
                a = a + 1;
                if (a % 5 == 0)
                {
                    printf("\n");
                }
            }
        }
    }
    printf("the number is:%d", a);
    return 0;
}
