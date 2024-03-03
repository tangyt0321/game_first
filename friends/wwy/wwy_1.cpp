// n只猴子选大王666
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000
int main()
{
    int number[SIZE], m, n, i, j, k, a;
    printf("一共几只猴:");
    scanf("%d", &n);
    k = n;
    for (i = 0; i < n; i++)
    {
        number[i] = i + 1; //[1,2,3,4,5]
    }
    printf("报的数:");
    scanf("%d", &m);
    a = m;
    for (i = 0; i < n; i++)
    {

        if (number[i] == 0)
        {
            if (i == n - 1)
            {
                i = -1;
            }
            continue;
        }

        if (number[i] != 0)
        {
            m = m - 1;
            if (m == 0)
            {
                k--;
                if (k == 0)
                {
                    printf("%d号猴子是大王\n", i + 1);
                    break;
                }

                number[i] = 0;
                printf("%d号猴子被报死\n", i + 1);
                m = a;
            }
        }
        if (i == n - 1)
        {
            i = -1;
        }
    }
    system("pause");
    return 0;
}