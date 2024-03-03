#include <stdio.h>
void delete_string(char str[], char ch)
{
    int i;
    for (i = 0; i < 11; i++) // 第一位丢失
    {
        printf("%c", str[i]);
        /*if(str[i]==ch)
        {
            continue;
        }
        printf("%c",str[i]);*/
    }
}

int main()
{
    int i;
    char a[11], x;
    printf("input original string:");

    printf("\n");
    for (i = 0; i < 11; i++)
    {
        scanf("%c", &a[i]);
    }
    printf("input char <to delete>:");
    scanf("%c", &x); // 问题1
    printf("the string after delete:");
    // delete_string(a, x);
    return 0;
}