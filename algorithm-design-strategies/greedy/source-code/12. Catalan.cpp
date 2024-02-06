#include <iostream>
#define MAX_N 1000
using namespace std;

int TinhCatalan(int [], int);

int main()
{
    int n;
    int catalan[MAX_N];

    cin >> n;
    cout << TinhCatalan(catalan, n);

    return 0;
}

int TinhCatalan(int catalan[], int n)
{
    catalan[0] = catalan[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
            catalan[i] += (catalan[j] * catalan[i - j - 1]);
    }
    return catalan[n];
}
