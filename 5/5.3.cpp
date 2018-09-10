/* 5.3 Sum of Digits
 Given two integers S and L, consider all non-negative decimal integers without leading zeroes of length L.
 Find how many of them have sum of digits equal to S.

 0 <= S <= 162, 1 <= L <= 18

Idea: we initialise an array of 162 elements.
Scan the array from 1 to 162.

 */

#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#define ll long long

using std::array;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int s, l;
int num_ints;
array<ll, 163> counts = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};

void read_input()
{
    cin >> s >> l;
}

void append_count()
{
    array<ll, 163> new_counts = {0};
    for (int j = 0; j <= 9; j++)
    {
        for (int i = 0; i < 163; i++)
        {
            new_counts[i + j] += counts[i];
        }
    }
    counts = new_counts;
}

void generate_counts(int l)
{
    for (int i = 0; i < l - 1; i++)
    {
        append_count();
    }
}

int main()
{
    //std::ios_base::sync_with_stdio(false);
    read_input();
    // Generate all digit strings with length L
    // There are 10^L of them.
    if (s == 0 & l == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        generate_counts(l);

        /*
        for (int i = 0; i <= s; i++)
        {
            cout << i << ": " << counts[i] << endl;
        }
        */

        cout << counts[s] << endl;
    }

    return 0;
}