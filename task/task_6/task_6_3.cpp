#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[100], b[100];
    int i;
    cout << "Enter the string:";
    gets(a);
    cout << endl;
    for (i = 0; i < strlen(a); i++)
    {
        b[i] = a[strlen(a) - i - 1];
    }
    for (i = 0; i < strlen(a) - 1; i++)
    {
        if (a[i] != b[i])
        {
            cout << "String is not palindrome";
            system("pause");
        }
    }
    cout << "String is palindrome";
    system("pause");
    return 0;
}