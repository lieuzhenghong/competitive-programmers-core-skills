/*
 6.3 Longest Common Subsequence
 Given two sequences A and B of the same length, find the largest common subsequence; 
 that is, find the largest integer k such that there exist two sequences of indices
 i_0, i_1 , ..., i_n and
 j_0, j_1, ...., j_n 
 of length k such that for all 0 <= x <= n, A[x] = B[x].
 
 This is a 2D dynamic programming solution. We can calculate the current row's solution
 only from the previous row, so we can throw away earlier rows; this is necessary
 for my solution to pass.

*/

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

typedef array<std::pair<vector<int>, vector<int>>, 1001> row;

int length;
vector<int> a, b;
row curr;
row prev;

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

void fill_grid()
{
    for (int i = 0; i <= 1000; i++)
        curr[i] = {{}, {}};
    for (int i = 1; i <= length; i++) // row
    {
        prev = curr;
        curr = {};

        for (int j = 0; j <= length; j++)
        {
            if (j == 0)
            {
                curr[j] = {{}, {}};
                continue;
            }
            else
            {
                std::pair<vector<int>, vector<int>> first_pair = prev[j];
                std::pair<vector<int>, vector<int>> second_pair = curr[j - 1];
                if (a[i - 1] == b[j - 1])
                {
                    if (first_pair.first.size() > 0)
                    // We check for this condition because vector.back() of a vector of length 0
                    // is undefined behaviour
                    {
                        if (first_pair.first.back() != i - 1 && first_pair.second.back() != j - 1)
                        // We check for this condition because otherwise we could be
                        // "double counting" the same letter
                        {
                            first_pair.first.push_back(i - 1);
                            first_pair.second.push_back(j - 1);
                        }
                    }
                    else
                    {
                        first_pair.first.push_back(i - 1);
                        first_pair.second.push_back(j - 1);
                    }
                    if (second_pair.first.size() > 0)
                    {
                        if (second_pair.first.back() != i - 1 && second_pair.second.back() != j - 1)
                        {
                            second_pair.first.push_back(i - 1);
                            second_pair.second.push_back(j - 1);
                        }
                    }
                    else
                    {
                        second_pair.first.push_back(i - 1);
                        second_pair.second.push_back(j - 1);
                    }
                }
                curr[j] = (first_pair.first.size() >= second_pair.first.size()) ? first_pair : second_pair;
            }
        }
    }
}

int main()
{
    read_input();

    fill_grid();

    cout << curr[length].first.size() << endl;
    for (auto &a : curr[length].first)
    {
        cout << a << " ";
    }
    cout << endl;
    for (auto &a : curr[length].second)
    {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}