#include <iostream>
int king(int, int);

int main()
{
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);
    printf("The king is %d\n", king(n, m));
    system("pause");
    return 0;
}

int king(int n, int m)
{
    int i = 0;
    int j = 1;
    int count = m;
    int monkey[1000] = {0};
    for (i = 1; i <= n; i++) // 初始化猴子
    {
        monkey[i] = 1; // 是1的不淘汰
    }
    for (i = 1; i < n; i++) // 每次循环淘汰一只，淘汰n-1只
    {
        count = m;
        while (count != 0) // 报完数时停止
        {
            if (monkey[j] != 0) // 淘汰的不报数
            {
                count--;
            }

            j++;

            if (j > n) // 到了最后一只猴子
            {
                j = 1;
            }
        }
        int lose = (j == 1) ? n : j - 1;
        monkey[lose] = 0; // 值为0则被淘汰
        printf("%d Monkey failed.\n", lose);
    }
    for (j = 1; j <= n; j++)
    {
        if (monkey[j])
            break;
    }
    return j;
}