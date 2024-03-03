#include <stdio.h>
int main()
{
    int i, j;
    int a[5][3];
    printf("input the grade:\n");

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    int max, min;
    printf("\t\tmax\tmin\n");

    for (j = 0; j < 3; j++)
    {
        max = a[0][j];
        min = a[0][j];
        for (i = 0; i < 5; i++)
        {
            if (max < a[i][j])
                max = a[i][j];
            if (min > a[i][j])
                min = a[i][j];
        }
        printf("the %d class\t%d\t%d\n", j + 1, max, min);
    }

    return 0;
}
