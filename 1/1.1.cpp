#include <iostream>
#include <vector>

int main()
{
    int x, y, z;
    int index_of_first_occurrence = -1;
    std::vector<int> is = {0};
    std::cin >> x >> y >> z;

    if (z == 0)
    {
        std::cout << 0;
        return 0;
    }

    // 2000 is guaranteed to terminate. After all, the numbers
    // are positive. z <= 1000. The slowest a series can creep
    // up is +1. Hence, 2000 is enough to hit 1000.
    // Just run another 1000 loops why not right
    for (int i = 1; i <= 2000; i++)
    {
        if (i % 2)
        {
            is.push_back(is[i - 1] + x);
        }
        else
        {
            is.push_back(is[i - 1] - y);
        }
        if (is[i] == z)
        {
            index_of_first_occurrence = i;
            break;
        }
    }
    std::cout << index_of_first_occurrence;
    return 0;
}