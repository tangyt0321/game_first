#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string>
#include <cstring>
int main()
{
    char str[20];
    cout << "Enter a string: " << endl;
    cin.get(str, 20);
    for (int i = 0; i < strlen(str); i++)
    {
        cout << str[i];
    }
    cout << endl;
    cout << str << endl;
    puts(str);
    cin.get();
    cin.get();
    return 0;
}