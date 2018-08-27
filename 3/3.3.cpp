#include <iostream>
#include <iomanip>
#include <vector>

#define epsilon 1e-9;

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void read_input(vector<int> &ns)
{
    int num_nums;
    int tmp;
    cin >> num_nums;
    while (cin >> tmp)
        ns.push_back(tmp);
}

long long sum_ints(vector<int> &ns)
{
    long long i = 0;
    for (auto &n : ns)
    {
        i += n;
    }

    return i;
}
double sum_recips(vector<int> &ns)
{
    // Just do the naive approach for now
    double i = 0.0;
    for (auto &n : ns)
    {
        i += (1.0 / n);
    }
    return i;
}

int main()
{
    vector<int> ns;
    read_input(ns);

    long long i = sum_ints(ns);
    double d = sum_recips(ns);

    cout << i << endl;
    cout << d << endl;

    std::cout << std::setprecision(11) << i + d;

    return 0;
}