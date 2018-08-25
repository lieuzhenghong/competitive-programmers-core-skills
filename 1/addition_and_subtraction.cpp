#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int generate_ith_x(int x, int y, int i)
{
    int ith_x = x * i - (y * (i - 1));
    //ith_x = (x - y) * i + y;
    return ith_x;
}

int generate_ith_y(int x, int y, int i)
{
    int ith_y = x * i - (y * (i));
    return ith_y;
}

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    int result = -1;

    // your code
    //cout << "0 ";
    int counter = 0;
    for (int i = 1; i <= 1050; i++)
    {
        int ith_x = generate_ith_x(x, y, i);
        counter++;
        if (ith_x == z)
        {
            //cout << counter;
            result = counter;
            break;
        }
        int ith_y = generate_ith_y(x, y, i);
        counter++;
        if (ith_y == z)
        {
            result = counter;
            break;
        }
        //cout << generate_ith_x(x, y, i) << " ";
        //cout << generate_ith_y(x, y, i) << " ";
    }

    /*
    if ((z - y) % (x - y))
    {
        cout << -1 << endl;
    }
    */

    cout << result << endl;
    return 0;
}