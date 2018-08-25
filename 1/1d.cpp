#include <iostream>
#include <vector>
#include <string>

struct card
{
    int val;
    char suit;
};

void sort(card *c)
{
    // let's just do insertion sort since there are only 5 elements
    card tmp;
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (c[i].val > c[j].val)
            {
                tmp = c[j];
                c[j] = c[i];
                c[i] = tmp;
            }
        }
    }
}

void read_input(card *cards)
{
    using std::cin;
    using std::cout;
    using std::string;

    int counter = 0;
    string input_card;
    while (cin >> input_card)
    {
        int val;
        char suit = input_card.back();
        if (input_card[0] == 'A')
        {
            val = 14;
        }
        else if (input_card[0] == 'K')
        {
            val = 13;
        }
        else if (input_card[0] == 'Q')
        {
            val = 12;
        }
        else if (input_card[0] == 'J')
        {
            val = 11;
        }
        else if (input_card[0] == 'T')
        {
            val = 10;
        }
        else
        {
            input_card.pop_back();
            val = stoi(input_card);
        }
        cards[counter] = {val, suit};
        counter++;
    }
}

bool check_suits(card *cs)
{
    char suit = cs[0].suit;
    for (int i = 0; i < 5; i++)
    {
        if (suit != cs[i].suit)
        {
            return false;
        }
    }
    return true;
}

bool check_values(card *cs)
{
    // We know the cards are sorted
    int tmp;
    // First, do some preprocessing. If the last card is A and first
    // card is 2, then we convert the last card into a 1.
    if (cs[4].val == 14 && cs[0].val == 2)
    {
        cs[4].val = 1;
        sort(cs);
    }
    for (int i = 1; i < 5; i++)
    {
        if (cs[i].val != cs[0].val + i)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    using std::cin;
    using std::cout;
    using std::string;

    bool is_flush = true;
    card cards[5] = {0};
    read_input(cards);
    sort(cards);
    /*
    for (auto &c : cards)
    {
        cout << c.val << c.suit << " ";
    }
    */

    if (!check_suits(cards))
    {
        cout << "NO";
        return 0;
    }
    else if (!check_values(cards))
    {
        cout << "NO";
        return 0;
    }
    else
    {
        cout << "YES";
        return 0;
    }
}