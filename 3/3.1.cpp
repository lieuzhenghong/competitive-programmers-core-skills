#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#define epsilon 1e-8;

void read_input(int n, std::vector<int> &v1, std::vector<int> &v2)
{
    std::string tmp;
    std::cin >> n;
    std::string l1;
    std::string l2;
    std::string delimiter = ".";

    std::getline(std::cin, l1);
    std::getline(std::cin, l1);
    std::getline(std::cin, l2);

    std::istringstream iss1(l1);
    std::istringstream iss2(l2);

    //std::cout << "Line 1: " << std::endl;

    int integer_portion;
    int decimal_portion;
    int total;

    while (iss1 >> tmp)
    {
        //std::cout << tmp << ", " << std::endl;
        // Get last 3 digits of tmp after the decimal point
        integer_portion = std::stoi(tmp.substr(0, tmp.find(delimiter))) * 1000;
        decimal_portion = std::stoi(tmp.substr(tmp.find(delimiter) + 1, tmp.size()));

        total = integer_portion + decimal_portion;
        v1.push_back(total);
    }
    //std::cout << std::endl;

    //std::cout << "Line 2: " << std::endl;
    while (iss2 >> tmp)
    {
        integer_portion = std::stoi(tmp.substr(0, tmp.find(delimiter))) * 1000;
        decimal_portion = std::stoi(tmp.substr(tmp.find(delimiter) + 1, tmp.size()));
        total = integer_portion + decimal_portion;
        v2.push_back(total);
    }
    //std::cout << std::endl;
}

auto sum_input(std::vector<int> &v)
{
    long long sum = 0;
    for (auto &e : v)
    {
        sum += e;
    }

    return sum;
}

void print_output(int a)
{
    if (a == 0)
        std::cout << "SUM(A)=SUM(B)";
    else if (a == 1)
        std::cout << "SUM(A)>SUM(B)";
    else
        std::cout << "SUM(A)<SUM(B)";
}

int main()
{
    int n;
    double e = epsilon;
    std::vector<int> first_vec, second_vec;
    read_input(n, first_vec, second_vec);

    long long first_sum = sum_input(first_vec);
    long long second_sum = sum_input(second_vec);

    //std::cout << first_sum << " " << second_sum << std::endl;

    if (first_sum > second_sum)
        print_output(1);
    else if (first_sum < second_sum)
        print_output(-1);
    else
        print_output(0);

    //print_output(are_they_equal(e, first_sum, second_sum));

    return 0;
}