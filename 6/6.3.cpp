#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <sstream>

using std::array;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

typedef array<array<std::pair<vector<int>, vector<int>>, 1001>, 1001> grid;

int length;
vector<int> a, b;
grid g;

void read_input()
{
    int tmp;
    std::string arr1;
    std::string arr2;
    std::string l;
    std::getline(cin, l);
    length = stoi(l);
    std::getline(cin, arr1);
    std::getline(cin, arr2);
    std::istringstream iss(arr1);
    while (iss >> tmp)
    {
        a.push_back(tmp);
    }
    std::istringstream is(arr2);
    while (is >> tmp)
    {
        b.push_back(tmp);
    }
    // split by space
}

void print_grid()
{
    for (int i = 0; i <= length; i++)
    {
        for (int j = 0; j <= length; j++)
        {
            cout << "[";
            cout << "{";
            for (auto &p : g[i][j].first)
            {
                cout << p << ",";
            }
            cout << "}";
            cout << "{";
            for (auto &p : g[i][j].second)
            {
                cout << p << ",";
            }
            cout << "}";
            cout << "]";
        }
        cout << endl;
    }
}

void fill_grid()
{
    for (int i = 0; i <= 1000; i++)
        g[0][i] = {{}, {}};
    for (int j = 0; j <= 1000; j++)
        g[j][0] = {{}, {}};

    for (int i = 1; i <= length; i++) // row
    {
        for (int j = 1; j <= length; j++)
        {
            std::pair<vector<int>, vector<int>> first_pair = g[i - 1][j];
            std::pair<vector<int>, vector<int>> second_pair = g[i][j - 1];
            g[i][j] = (first_pair.first.size() >= second_pair.first.size()) ? first_pair : second_pair;
            if (a[i - 1] == b[j - 1])
            {
                if (g[i][j].first.size() > 0)
                {
                    if (g[i][j].first.back() == i - 1 || g[i][j].second.back() == j - 1)
                        continue;
                }
                g[i][j].first.push_back(i - 1);
                g[i][j].second.push_back(j - 1);
            }
        }
    }
}

int main()
{
    read_input();

    fill_grid();

    cout << g[length][length].first.size() << endl;

    for (auto &a : g[length][length].first)
    {
        cout << a << " ";
    }
    cout << endl;

    for (auto &a : g[length][length].second)
    {
        cout << a << " ";
    }
    cout << endl;

    //print_grid();

    return 0;
}