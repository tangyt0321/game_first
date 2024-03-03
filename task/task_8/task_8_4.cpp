#include <iostream>
using namespace std;

float average = 0.00;

int main()
{
    int num(float a[], int n);

    float a[10];
    int n = 10;
    cout << "Enter the scores: ";
    for (int i = 0; i < 10; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        average += a[i];
    }
    average = average / n;
    cout << "The average is " << average << endl;
    cout << "The number of students above the average is " << num(a, n);
    system("pause");
    return 0;
}

int num(float a[], int n)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > average)
            c++;
    }
    return c;
}