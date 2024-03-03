#include <iostream>
using namespace std;

char *seek(char *a, char *b, char *c)
{
    int i, j, k = 0, x = 0, p;
    char ch;
    for (i = 0; *(a + i) != '\0'; i++)
    {
        p = 0;
        for (j = 0; *(b + j) != '\0'; j++)
        {
            if (*(a + i) == *(b + j))
            {
                ch = *(a + i);
                p = 1;
                break;
            }
        }
        if (p == 0)
            continue;
        for (x = 0; x < k + 1; x++)
        {
            if (ch == *(c + x))
                break;
            *(c + k) = ch;
            k++;
            break;
        }
    }
    *(c + k) = '\0';
    return c;
}

int main()
{
    char a[100], b[100], c[100];
    cout << "输入a：";
    gets(a);
    cout << "输出b：";
    gets(b);
    cout << "结果c：";
    cout << seek(a, b, c);
    return 0;
}