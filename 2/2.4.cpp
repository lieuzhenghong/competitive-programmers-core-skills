#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s;
    long long sum = 0;
    int tmp = 0;
    bool minus = false;
    cin >> s;

    for (auto &c : s)
    {
        if (c == '+' || c == '-')
        {
            if (minus)
            {
                sum -= tmp;
            }
            else
            {
                sum += tmp;
            }
            if (c == '+')
            {
                minus = false;
            }
            else if (c == '-')
            {
                minus = true;
            }
            tmp = 0;
            //cout << "sum: " << sum << endl;
        }
        else
        {
            tmp = tmp * 10 + int(c - 48);
        }
    }
    sum = (minus) ? sum - tmp : sum + tmp;
    cout << sum;
}
