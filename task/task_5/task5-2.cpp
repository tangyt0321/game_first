#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int a[10], n = 10, x, y = 0;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }
    printf("\nenter a number: ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++)
    {
        if (a[i] > x)
        {
            printf("%d ", a[i]);
            y++;
        }
    }
    printf("\nin have %d numbers\n", y);
    system("pause");
    return 0;
}
