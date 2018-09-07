#include <iostream>
#include <vector>
#include <array>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

std::map<int, std::pair<int, int>> smallest_LIS;
vector<int> seq;
int n;
int LIS = 0;

void read_input()
{
    int a;
    cin >> n;
    while (cin >> a)
    {
        seq.push_back(a);
    }
}

void print_smallest_LIS()
{
    for (auto &lis : smallest_LIS)
    {
        cout << lis.first << " : " << lis.second.first << " " << lis.second.second << endl;
    }
}

int main()
{
    read_input();

    for (int i = 0; i < seq.size(); i++)
    {
        if (i == 0)
        {
            smallest_LIS[1] = {seq[i], 0};
            LIS = 1;
        }
        else if (smallest_LIS[1].first >= seq[i])
        {
            smallest_LIS[1] = {seq[i], 0};
        }
        else
        {
            for (auto lis = smallest_LIS.rbegin(); lis != smallest_LIS.rend(); ++lis)
            {
                if (seq[i] > lis->second.first)
                {
                    //cout << "Found a better LIS, breaking" << endl;
                    smallest_LIS[lis->first + 1] = {seq[i], i};
                    break;
                }
            }
        }
        //print_smallest_LIS();
    }

    //print_smallest_LIS();

    cout << smallest_LIS.size() << endl;
}