/*
6.4 Maximal Sum Square
Given an nxn matrix A of integers an an integer k,
find a kxk submatrix of A with the maximum sum of elements.

1 <= k <= n <= 700
Integers in the matrix
are guaranteed to be <= 1000

That means 700 * 700 * 1000 <= INT_MAX
so we can use integers
*/

#include <iostream>
#include <sstream>
#include <string>
#include <array>

using std::array;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

typedef array<int, 700> row;

int n, k, subgrid_size;
array<row, 700> grid = {};
array<row, 700> subgrid = {};

void read_input()
{
    string nk;
    getline(cin, nk);
    std::istringstream iss(nk);
    iss >> n >> k;
    subgrid_size = n - k + 1;

    int rw = 0;
    int col = 0;
    int tmp;
    while (cin >> tmp)
    {
        grid[rw][col] = tmp;
        col++;
        if (col >= n)
        {
            col = 0;
            rw++;
        }
    }
}

void print_grid(array<row, 700> &g, int n)
{
    for (int rw = 0; rw < n; rw++)
    {
        for (int col = 0; col < n; col++)
        {
            cout << g[rw][col] << " ";
        }
        cout << endl;
    }
}

auto sum_subgrid(int i, int j)
{
    int sum = 0;
    cout << "Summing subgrid " << i << " " << j << endl;
    for (int a = 0; a < k; a++)
    {
        for (int b = 0; b < k; b++)
        {
            sum += grid[a + i][b + j];
        }
    }
    cout << "Sum: " << sum << endl;
    return sum;

    // The key is to realise that you can borrow the computation of the previous subgrid
}

int fill_subgrid()
{
    int max_sum = 0;
    cout << "subgrid size: " << subgrid_size << endl;
    for (int i = 0; i < subgrid_size; i++)
    {
        for (int j = 0; j < subgrid_size; j++)
        {
            subgrid[i][j] = sum_subgrid(i, j);
            if (subgrid[i][j] > max_sum)
            {
                max_sum = subgrid[i][j];
            }
        }
    }
    return max_sum;
}

int main()
{
    read_input();
    //cout << n << " " << k << endl;
    print_grid(grid, n);
    int max_sum = fill_subgrid();
    cout << " ------- " << endl;
    print_grid(subgrid, subgrid_size);
    cout << " ------- " << endl;
    cout << "Max sum: " << max_sum << endl;
}