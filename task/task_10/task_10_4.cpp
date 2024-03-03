#include <iostream>
using namespace std;
#include <string.h>

char *addat(char *s1, char *s2)
{
    int a = strlen(s1), b = 0, c = 0;
    for (int i = 0; i < strlen(s2); i++)
    {
        for (int j = 0; j < a; j++)
        {
            c = 0;
            if (*(s2 + i) == *(s1 + j))
            {
                c = -1;
                break;
            }
        }
        if (c == -1)
            continue;
        *(s1 + strlen(s2) + b) = *(s2 + i);
        b++;
    }
    return s1;
}

int main()
{
    char s1[100], s2[100];
    cout << "Enter the string 1:";
    cin >> s1;
    cout << "Enter the string 2:";
    cin >> s2;
    cout << "The resultant string is:";
    cout << addat(s1, s2) << endl;
    system("pause");
    return 0;
}