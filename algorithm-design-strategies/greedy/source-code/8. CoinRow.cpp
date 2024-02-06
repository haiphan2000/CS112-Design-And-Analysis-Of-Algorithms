#include <iostream>
#define MAX_N 1000
using namespace std;

void Nhap(int [], int &);
int CoinRow(int [], int, int []);

int main()
{
    int n;
    int coin[MAX_N];
    int max_coin[MAX_N];

    Nhap(coin, n);
    cout << CoinRow(coin, n, max_coin);

    return 0;
}

void Nhap(int coin[], int &n)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> coin[i];
}

int CoinRow(int coin[], int n, int max_coin[])
{
    max_coin[0] = 0;
    max_coin[1] = coin[1];
    for (int i = 2; i <= n; i++)
        max_coin[i] = max(coin[i] + max_coin[i - 2], max_coin[i - 1]);
    return max_coin[n];
}
