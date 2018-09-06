/* Greatest Manhattan Distance */
// Brute force solution --- runs in O(n^2) time

#include <vector>
#include <array>
#include <iostream>

using std::array;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct pt
{
    int x;
    int y;
};

void read_input(int &n, vector<pt> &pts)
{
    pt p;
    cin >> n;
    pts.push_back({0, 0}); //index 1
    while (cin >> p.x >> p.y)
    {
        pts.push_back(p);
    }
}

int manhattan(pt &a, pt &b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

auto best_dist_subset(int i, vector<pt> &pts)
{
    array<int, 3> best_pts = {1, 1, 0};

    if (i == 1)
    {
        return best_pts;
    }

    for (int j = 1; j < i; ++j)
    {
        //cout << "Checking points " << j << " and " << i << endl;
        int mhd = manhattan(pts[j], pts[i]);
        if (mhd > best_pts[2])
        {
            best_pts = {j, i, mhd};
        }
    }
    return best_pts;
}

/*
array<int, 2> best_dist_subset(int i, vector<pt> &pts)
{
    if (i == 1)
    {
        return {1, 1};
    }

    int best_dist = 0;
    array<int, 2> best_pts = {0, 0};
    for (int j = 1; j < i; j++)
    {
        for (int k = j + 1; k <= i; k++)
        {
            cout << "Checking points " << j << " and " << k << endl;
            if ((manhattan(pts[j], pts[k]) > best_dist))
            {
                best_dist = manhattan(pts[j], pts[k]);
                best_pts = {j, k};
            }
        }
    }
    return best_pts;
}
*/

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    vector<pt> pts;
    read_input(n, pts);

    array<int, 3> cbd = {1, 1, 0};
    for (int i = 1; i <= n; i++)
    {
        array<int, 3> bds = best_dist_subset(i, pts);
        if (bds[2] > cbd[2])
        {
            cbd = bds;
        }
        cout << cbd[0] << " " << cbd[1] << '\n';
    }

    return 0;
}