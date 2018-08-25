#include <iostream>
#include <vector>
#include <array>

using std::array;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void populate_lookup_table(int n, array<array<int, 9>, 9> &table, vector<vector<int>> &grid)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            table[i][j] = grid[i][j];
            table[j][i] = grid[i][j];
        }
    }
}

vector<vector<int>> generate_fac(int n)
{
    vector<vector<int>> v1, v2;
    if (n == 1)
    {
        v1 = {{1}};
    }
    else
    {
        v2 = generate_fac(n - 1);
        for (int i = 0; i < n; i++)
        {
            vector<vector<int>> w = v2;
            for (auto &v : w)
            {
                v.insert(v.begin() + i, n);
            }
            v1.insert(v1.end(), w.begin(), w.end());
        }
    }
    /*
    for (auto &v : v1)
    {
        cout << "{";
        for (auto &e : v)
        {
            cout << e << " ";
        }
        cout << "}, ";
    }
    cout << endl;
    */
    return v1;
}

int perm_cost(vector<int> &v, vector<vector<int>> &matrix)
{
    int c = 0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        // The numbers are 1-indexed but the
        // matrix is 0-indexed
        c += matrix[v[i] - 1][v[i + 1] - 1];
    }
    return c;
}

void print_perm(vector<int> &v)
{
    cout << "{";
    for (auto &e : v)
    {
        cout << e << " ";
    }
    cout << "} ";
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    vector<int> result;

    vector<vector<int>> perms;
    perms = generate_fac(n);

    int best_cost = 1000000;

    for (auto &p : perms)
    {
        int curr_cost = perm_cost(p, a);
        if (best_cost > curr_cost)
        {
            best_cost = perm_cost(p, a);
            result = p;
        }
    }

    // Print result
    for (int i = 0; i < result.size(); ++i)
    {
        if (i != 0)
            cout << ' ';
        cout << result[i];
    }

    return 0;
}