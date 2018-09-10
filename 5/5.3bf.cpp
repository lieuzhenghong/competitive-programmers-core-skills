/* 5.3 Sum of Digits
 Given two integers S and L, consider all non-negative decimal integers without leading zeroes of length L.
 Find how many of them have sum of digits equal to S.

 0 <= S <= 162, 1 <= L <= 18

Brute force solution.
10^n complexity.
 */

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#define ll long long

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int s, l;
int num_ints;
vector<ll> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};

void read_input()
{
    cin >> s >> l;
}

int digit_sum(ll x)
{
    int sum = 0;
    while (x >= 10)
    {
        sum += x % 10;
        x /= 10;
    }
    sum += x;
    return sum;
}

auto filter(int sum, vector<ll> &nums)
{
    nums.erase(std::remove_if(nums.begin(), nums.end(), [sum](ll x) { return digit_sum(x) != sum; }), nums.end());
}

auto filter_gt(int sum, vector<ll> &nums)
{
    nums.erase(std::remove_if(nums.begin(), nums.end(), [sum](ll x) { return digit_sum(x) > sum; }), nums.end());
}

void append_num()
{
    vector<ll> new_nums;
    for (auto &num : nums)
    {
        for (int i = 0; i < 10; i++)
        {
            new_nums.push_back(num * 10 + i);
        }
    }
    nums = new_nums;
}

auto generate_nums(int len)
{
    for (int i = 0; i < len; i++)
    {
        // Filter first: remove those that exceed the sum
        filter_gt(s, nums);
        append_num();
    }
}

void print_nums(vector<ll> &nums)
{
    cout << "[ ";
    for (auto &num : nums)
    {
        cout << num << " ";
    }
    cout << "]" << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    read_input();
    // Generate all digit strings with length L
    // There are 10^L of them.
    generate_nums(l - 1);

    //print_nums(nums);
    /*
    for (auto &num : nums)
    {
        cout << num << ": " << digit_sum(num) << endl;
    }
    */
    filter(s, nums);
    //print_nums(nums);
    cout << nums.size() << endl;

    return 0;
}