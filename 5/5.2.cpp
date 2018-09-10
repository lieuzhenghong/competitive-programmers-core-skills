/* Minimum edit distance */
// Practice dynamic programming algorithm
#include <iostream>
#include <vector>
#include <array>
#include <string>
#define MAX_INT 2147483647

using std::array;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int ins_cost, del_cost, sub_cost;
string a;
string b;
array<array<int, 1001>, 1001> grid;

auto min = [](int a, int b, int c) {
    if (a <= b)
    {
        return (a < c) ? a : c;
    }
    else // a > b
    {
        return (b < c) ? b : c;
    }
};

auto substcost(int i, int j)
{
    //cout << "looking at" << i << " " << j << endl;
    //cout << a[i] << b[j] << endl;
    if (a[i - 1] == b[j - 1])
    {
        //cout << i - 1 << " " << j - 1 << " " << a[i - 1] << b[j - 1] << endl;
        return 0;
    }
    if (sub_cost > (ins_cost + del_cost))
    {
        return ins_cost + del_cost;
    }
    return sub_cost;
}

void read_input()
{
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    cin >> a >> b;
    cin >> ins_cost >> del_cost >> sub_cost;
}

int cost(int i, int j)
{
    //cout << "Currently considering " << i << " " << j << endl;
    if (grid[i][j] != MAX_INT)
    {
        return grid[i][j];
    }
    else
    {
        if (i == 0)
        {
            grid[i][j] = j * ins_cost;
        }
        else if (j == 0)
        {
            grid[i][j] = i * del_cost;
        }
        else
        {
            grid[i][j] = min(
                cost(i, j - 1) + ins_cost,
                cost(i - 1, j) + del_cost,
                cost(i - 1, j - 1) + substcost(i, j));
        }
        /*
        cout << "Grid cost for << "
             << "[ " << i << ", " << j << " ]: " << grid[i][j] << endl;
             */
        return grid[i][j];
    }
}

void init_grid()
{
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
            grid[i][j] = MAX_INT;
        }
    }
}

int main()
{
    read_input();
    init_grid();

    cout << cost(a.size(), b.size()) << endl;

    return 0;
}