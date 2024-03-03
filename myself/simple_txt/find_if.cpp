#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void know_your_algorithms()
{
    const std::vector<int> data = {-1, -2, 3, 4, 5};

    const auto is_positive = [](const auto &x)
    { return x > 0; };
    auto first_pos_it = std::find_if(
        data.cbegin(),
        data.cend(),
        is_positive);
    // use first_pos_it to access the first positive element
}

int main()
{
    void know_your_algorithms();
    cin.get();
    cin.get();
    return 0;
}
