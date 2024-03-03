#include <stdio.h>
#include <stdlib.h>
int calculate(int time)
{
    if (time < 10)
        return 1;
    if (time < 50 && time >= 10)
        return 2;
    if (time >= 50 && time < 65)
        return 3;
    if (time >= 65)
        return 4;
}

int main()
{
    int time;
    float expense;
    printf("time:");
    scanf("%d", &time);
    switch (calculate(time))
    {
    case 1:
        expense = 25;
        break;
    case 2:
        expense = time * 2.5;
        break;
    case 3:
        expense = time * 2;
        break;
    case 4:
        expense = 130;
    }
    printf("expense:%3.1f\n", expense);
    system("pause");
    return 0;
}
