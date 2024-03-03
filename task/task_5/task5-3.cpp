#include <stdio.h>
int main()
{
    printf("please enter the array: ");
    int a[11];
    for (int i = 1; i < 11; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("enter the number: ");
    scanf("%d", &a[0]);
    for (int i = 0; i < 11; i++)
    {
        for (int i = 0; i < 10; i++)
        {
            if (a[i] > a[i + 1])
            {
                int t;
                t = a[i];
                a[i] = a[i + 1];
                a[i + 1] = t;
            }
        }
    }
    for (int i = 0; i < 11; i++)
        printf("%d ", a[i]);
    return 0;
}
