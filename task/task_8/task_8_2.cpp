#include <iostream>
using namespace std;
#include <cstring>

int at(char s[], char c)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == c)
        {
            return i+1;
        }
    }
}

int main()
{
    char s[100];
    cout << "Enter a string: ";
    cin.get(s, 100);
    char c;
    cout << "Enter a character: ";
    cin >> c;
    cout << "The character occurs at index: " << at(s, c);
    cin.get();
    cin.get();
    return 0;
}