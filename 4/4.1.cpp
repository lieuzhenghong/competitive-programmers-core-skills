/* The Most Frequent Symbol */
#include <iostream>
#include <array>
#include <vector>

using std::array;
using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::vector;

typedef array<int, 26> letter_array;
struct query
{
    int l;
    int r;
};

void read_input(string &s, int &n, vector<query> &qs)
{
    cin >> s;
    cin >> n;
    query q = {};
    while (cin >> q.l >> q.r)
    {
        q.l--;
        q.r--;
        qs.push_back(q);
    }
}

void count_symbols(string &s, vector<letter_array> &las)
{
    letter_array la = {0};
    int c = int(s[0]) - 97;
    la[c] = 1;
    las.push_back(la);

    for (int i = 1; i < s.size(); i++)
    {
        int c = int(s[i]) - 97;
        letter_array la = las[i - 1];
        la[c] += 1;
        las.push_back(la);
    }

    /*
    for (auto &la : las)
    {
        cout << "[ ";
        for (auto &c : la)
        {
            cout << c << ", ";
        }
        cout << "]" << endl;
    }
    */
}

void mfs(query &q, vector<letter_array> &las)
{

    letter_array la1;
    if (q.l == 0)
        la1 = {0};
    else
    {
        la1 = las[q.l - 1];
    }
    letter_array la2 = las[q.r];

    letter_array result = {};

    int best_count = 0;
    int mcl = 0;
    for (int i = 0; i < result.size(); i++)
    {
        result[i] = la2[i] - la1[i];
        if (result[i] > best_count)
        {
            best_count = result[i];
            mcl = i;
        }
    }
    //cout << "Best count: " << best_count << " letter: " << char(mcl + 97) << endl;
    cout << char(mcl + 97) << endl;
}

int main()
{
    string s;
    int n;
    vector<query> queries;
    vector<letter_array> letter_arrays;
    read_input(s, n, queries);
    count_symbols(s, letter_arrays);
    for (auto &query : queries)
    {
        mfs(query, letter_arrays);
    }
    return 0;
}