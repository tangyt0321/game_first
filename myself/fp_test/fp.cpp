#include <iostream>
using namespace std;
#include <stdlib.h>
int main()
{
    FILE *fp;
    char ch, filename[20];
    cout << "Enter the filename:";
    cin >> filename;
    getchar();
    if ((fp = fopen(filename, "a+")) == NULL)
    {
        cout << "Cannot open file" << endl;
        exit(0);
    }
    cout << "Enter the text to be written:";
    ch = getchar();
    while (ch != '#')
    {
        fputc(ch, fp);
        putchar(ch);
        ch = getchar();
    }
    fprintf(fp, "hello world");
    fclose(fp);
    cout << endl;
    cout << "File created successfully" << endl;
    putchar(10);
    system("pause");
    return 0;
}