// Simple and easy: make two passes over the array
// The first past finds the maximum, the second
// pass finds either the first occurrence or the third, and
// deletes it
// O(n) running time

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> result;

    // your code

    int max = 0;
    int maxes = 0;
    vector<int> max_pos;

    for (auto e : a)
    {
        if (e > max)
        {
            max = e;
        }
    }

    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] == max)
        {
            maxes++;
            max_pos.push_back(i);
        }
    }

    // erase the maximum (first or third maximum)

    if (maxes >= 3)
    {
        a.erase(a.begin() + max_pos[2]);
    }
    else
    {
        a.erase(a.begin() + max_pos[0]);
    }

    // Push to result
    for (auto e : a)
    {
        result.push_back(e);
    }

    for (int i = 0; i < result.size(); ++i)
    {
        if (i != 0)
            cout << ' ';
        cout << result[i];
    }
    cout << endl;

    return 0;
}