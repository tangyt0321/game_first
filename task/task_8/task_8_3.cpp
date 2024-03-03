#include <iostream>
using namespace std;
#include <cstring>

void delet_string(char str[], char ch)
{
    int x = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ch)
        {
            str[i] = ' ';
            continue;
        }
        str[x] = str[i];
        x++;
    }
    str[x] = '\0';
}

int main()
{
    char str[100], ch;
    cout << "Enter string: ";
    cin.get(str, 100);
    cout << "Enter character to delete: ";
    cin >> ch;
    delet_string(str, ch);
    cout << str;
    cin.get();
    cin.get();
    return 0;
}