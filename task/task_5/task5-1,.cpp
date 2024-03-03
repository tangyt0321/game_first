#include <stdio.h>
int main()
{
    int a[10], i, max, min;
    float all = 0;
    printf("Enter the elements of the array: ");
    for (i = 0; i < 10; ++i)
    {
        scanf("%d", &a[i]);
    }
    max = a[0];
    min = a[0];
    for (i = 0; i < 10; i++)
    {
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
        all = all + a[i];
    }
    printf("The maximum element is %d\n", max);
    printf("The minimum element is %d\n", min);
    printf("The average of elements is %2.1f\n", all / i);
    return 0;
}