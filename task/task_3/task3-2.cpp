#include <stdio.h>
int main()
{
    int j = 0;
    for (int i = 50; i < 100; i++)
        if (i % 2 != 0)
            j = j + i;
    printf("%d\n", j);
    return 0;
}