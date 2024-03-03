#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*int main()
{
    int a,i,j,h=0,k=0;
    printf("请输入二进制:");
    scanf("%d",&a);
    j=log10(a)+1;
    for(i=0;i<j;i++)
    {
        h=a/pow(10,i);
        if(h%10!=1&&h%10!=0)
        {
            printf("错误,请输入有效二进制!");
            break;
        }
        if(h%10==1)
        {
            k+=pow(2,i);
        }
    }
    printf("\n结果是:%d",k);
    return 0;
}*/
int cc(int a)
{
    int x = 0;
    while (a != 0)
    {
        for (int i = 0; i < a; i++)
        {
            if (pow(2, i) > a)
            {
                x += pow(10, i - 1);
                a -= pow(2, i - 1);
                break;
            }
            if (a == 2)
            {
                x += 10;
                a -= 2;
                break;
            }
            if (a == 1)
            {
                x += 1;
                a -= 1;
                break;
            }
        }
    }
    return x;
}
int main()
{
    int a, m, n, x;
    printf("请输入十进制:");
    scanf("%d", &a);
    x = cc(a);
    printf("%d", x);
    system("pause");
    return 0;
}