#include <iostream>
using namespace std;

int strcmp(char *str1, char *str2)
{
    for (int i = 0; *(str1 + i) != '\0' && *(str2 + i) != '\0'; i++)
    {
        if (*(str1 + i) > *(str2 + i))
            return 1;
        else if (*(str1 + i) < *(str2 + i))
            return -1;
        else
            continue;
    }
}

int main()
{
    char str1[100], str2[100];
    cout << "Enter the first string : ";
    cin >> str1;
    cout << "Enter the second string : ";
    cin >> str2;
    cout << "the result is: " << strcmp(str1, str2) << endl;
    system("pause");
    return 0;
}