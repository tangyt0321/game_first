#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>

void fun(char *a);

int main()
{
    int max;
    char *s;
    s = (char *)calloc(max, sizeof(char));
    cout << "输入：";
    cin >> s;
    fun(s);
    cout << "输出：" << s;
    free(s);
    return 0;
}

void fun(char *a)
{
    int i = 0, j = 0, k;
    for (; i < 2 * strlen(a); i++, j++)
    {
        if (j % 3 == 2)
        {
            for (k = 2 * strlen(a) - 1; k > i; k--)
                *(a + k) = *(a + k - 1);
            *(a + i) = ' ';
        }
    }
}