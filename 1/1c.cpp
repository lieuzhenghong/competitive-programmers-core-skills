#include <iostream>
#include <string>

int main()
{
    using std::cin;
    using std::cout;
    using std::string;

    string s;
    bool all_nines = true;
    int num_digits = 0;
    cin >> s;

    for (auto &c : s)
    {
        num_digits++;
        if (c != '9')
        {
            all_nines = false;
        }
    }

    if (all_nines)
    {
        num_digits++;
    }

    cout << num_digits;

    return 0;
}