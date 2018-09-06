#include <iostream>
#include <array>

using std::array;
using std::cin;
using std::cout;
using std::endl;

void print_out(array<int, 100001> &xs)
{
    for (int i = 1; i < 100001; i++)
    {
        if (xs[i] == 0)
            continue;
        else
            cout << i << " " << xs[i] << '\n';
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    array<int, 100001> S = {0};

    cin >> n;
    int l;
    int r;

    while (cin >> l >> r)
    {
        for (int i = l; i <= r; i++)
        {
            S[i]++;
        }
    }

    print_out(S);

    return 0;
}