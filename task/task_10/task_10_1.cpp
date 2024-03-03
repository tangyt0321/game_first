#include <iostream>
using namespace std;

void replace(char *str, char c1, char c2)
{
    for (int i = 0; *(str + i) != '\0'; i++)
    {
        if (*(str + i) == c1)
        {
            *(str + i) = c2;
        }
    }
}

int main()
{
    char str[100];
    char c1, c2;
    cout << "Enter the string: ";
    cin >> str;
    cout << "Enter the characters to be replaced: ";
    cin >> c1;
    cout << "Enter the character to replace: ";
    cin >> c2;
    replace(str, c1, c2);
    cout << "The string after replacement: ";
    cout << str << endl;
    system("pause");
    return 0;
}