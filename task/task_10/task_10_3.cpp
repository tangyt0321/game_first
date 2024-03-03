#include <iostream>
using namespace std;
#include <string.h>

char *fun(char *s1, char *s2)
{
    if (strlen(s1) > strlen(s2))
        return s1;
    else
        return s2;
}

int main()
{
    char s1[100], s2[100];
    cout << "Enter the string 1: ";
    cin >> s1;
    cout << "Enter the string 2: ";
    cin >> s2;
    fun(s1, s2);
    cout << "The longer string is: " << fun(s1, s2) << endl;
    system("pause");
    return 0;
}