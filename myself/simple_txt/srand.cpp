#include <iostream>
#include <ctime>
#include <cstdlib>
int main()
{
    int a;
    srand(time(NULL));
    a = rand() % 100;
    std::cout << a;
    std::cin.get();
    return 0;
}