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

auto sum_subgrid(int row, int col)
{
    int sum = 0;
    if (row == 0 && col == 0)
    {
        for (int a = 0; a < k; a++)
        {
            for (int b = 0; b < k; b++)
            {
                sum += grid[a + row][b + col];
            }
        }
    }
    else if (row == 0)
    {
        sum = subgrid[row][col - 1];
        for (int a = 0; a < k; a++)
        {
            sum += (grid[a + row][k + col - 1] - grid[a + row][col - 1]);
        }
    }
    else if (col == 0)
    {
        sum = subgrid[row - 1][col];
        for (int a = 0; a < k; a++)
        {
            sum += grid[k + row - 1][a + col] - grid[row - 1][a + col];
        }
    }
    else
    {
        int a = subgrid[row - 1][col - 1];
        int b = subgrid[row - 1][col];
        int c = subgrid[row][col - 1];
        sum = b + c - a +
              grid[row + k - 1][col + k - 1] +
              grid[row - 1][col - 1] -
              grid[row + k - 1][col - 1] -
              grid[row - 1][col + k - 1];
    }

    return sum;
    // The key is to realise that you can borrow the computation of the previous subgrid
}

int fill_subgrid()
{
    int max_sum = 0;
    //cout << "subgrid size: " << subgrid_size << endl;
    for (int row = 0; row < subgrid_size; row++)
    {
        for (int col = 0; col < subgrid_size; col++)
        {
            subgrid[row][col] = sum_subgrid(row, col);
            if (subgrid[row][col] > max_sum)
            {
                max_sum = subgrid[row][col];
            }
        }
    }
    return max_sum;
}

int main()
{
    read_input();
    //cout << n << " " << k << endl;
    //print_grid(grid, n);
    int max_sum = fill_subgrid();
    //cout << " ------- " << endl;
    //print_grid(subgrid, subgrid_size);
    //cout << " ------- " << endl;
    cout << max_sum << endl;
}