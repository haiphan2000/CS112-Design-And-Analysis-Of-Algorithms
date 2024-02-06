#include <iostream>
#include <string>
using namespace std;

void XoaSo0Dau(string &);
string RemoveDigits(string, int, int);

int main()
{
    int n;
    string number;
    int k;

    cin >> number;
    n = number.length();
    cin >> k;
    cout << RemoveDigits(number, n, k);

    return 0;
}

void XoaSo0Dau(string &number)
{
    while (number[0] == '0')
        number.erase(0, 1);
    if (number.length() == 0)
        number = "0";
}

string RemoveDigits(string number, int n, int k)
{
    for (int i = 1; i <= k; i++)
    {
        int pos = 0;
        while (number[pos] < number[pos + 1] && pos < n)
            pos++;
        number.erase(number.begin() + pos);
    }
    XoaSo0Dau(number);
    return number;
}
