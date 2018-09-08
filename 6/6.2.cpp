#include <iostream>
#include <array>
#include <vector>

#define MAX_MATRICES 150
#define lanjiao long long
#define MAX_LLONG 9223372036854775807

using std::array;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

typedef array<array<lanjiao, MAX_MATRICES>, MAX_MATRICES> grid;

int num_matrices = 0;
grid costs = {};

vector<int> dims;

void read_input()
{
    int d;
    cin >> num_matrices;
    while (cin >> d)
    {
        dims.push_back(d);
    }
}

lanjiao min_cost(int l, int r)
{
    auto min = [](lanjiao a, lanjiao b) { return (a < b) ? a : b; };
    /*
    cout << "Called on the array "
         << "[ ";
    for (int i = l; i <= r; i++)
    {
        cout << dims[i] << ", ";
    }
    cout << "] " << endl;
    */

    if (r == l + 1)
    {
        costs[l][r] = 0;
        return 0;
    }
    else
    {
        lanjiao best_cost = MAX_LLONG;
        if (costs[l][r] != MAX_LLONG)
        {
            return costs[l][r];
        }
        else
        {
            for (int k = l + 1; k < r; k++)
            {
                best_cost = min(best_cost,
                                min_cost(l, k) +
                                    min_cost(k, r) +
                                    dims[l] * dims[k] * dims[r]);
            }
            //cout << "Min cost :" << best_cost << endl;
            costs[l][r] = best_cost;
            return best_cost;
        }
    }
}

int main()
{
    //std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < MAX_MATRICES; i++)
    {
        for (int j = 0; j < MAX_MATRICES; j++)
        {
            costs[i][j] = MAX_LLONG;
        }
    }

    read_input();
    lanjiao mc = min_cost(0, num_matrices);
    cout << mc << endl;
    return 0;
}