#include <iostream>
#include <vector>
#include <array>
#include <memory>
#define ll long long

using std::array;
using std::cin;
using std::cout;
using std::unique_ptr;

typedef array<array<int, 2000>, 2000> grid;

int min(int a, int b)
{
    return (a < b) ? a : b;
}

void populate_array(int num_elems, unique_ptr<grid> &mins)
{
    for (int i = 0; i < num_elems; i++)
    {
        for (int j = 0; j < num_elems - 1; j++)
        {
            (*mins)[j][i + j + 1] = min((*mins)[j][i + j], (*mins)[j + 1][i + j + 1]);
        }
    }
}

int read_input_and_initialise_array(unique_ptr<grid> &mins)
{
    int counter = 0;
    int num_elems;
    int n;

    cin >> num_elems;
    while (cin >> n)
    {
        (*mins)[counter][counter] = n;
        counter++;
    }

    return num_elems;
}

void visualise_grid(int num_elems, unique_ptr<grid> &mins)
{
    for (int i = num_elems - 1; i >= 0; i--)
    {
        for (int j = 0; j < num_elems; j++)
        {
            cout << (*mins)[i][j] << " ";
        }
        cout << std::endl;
    }
}

ll sum_grid(int num_elems, unique_ptr<grid> &mins)
{
    ll sum = 0;

    for (int i = 0; i < num_elems; i++)
    {
        for (int j = i; j < num_elems; j++)
        {
            sum += (*mins)[i][j];
        }
    }

    return sum;
}

int main()
{
    unique_ptr<grid> mins(new grid);
    int num_elems = read_input_and_initialise_array(mins);

    // Iterate through the array
    populate_array(num_elems, mins);

    // Let's take a look at the grid
    //visualise_grid(num_elems, mins);

    cout << sum_grid(num_elems, mins);

    return 0;
}