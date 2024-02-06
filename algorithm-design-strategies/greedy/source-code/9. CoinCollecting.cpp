#include <iostream>
#define MAX_N 100
using namespace std;

void Nhap(int [][MAX_N], int &, int &);
int CollectCoin(int [][MAX_N], int, int);

int main()
{
    int n;
    int m;
    int board[MAX_N][MAX_N];

    Nhap(board, n, m);
    cout << CollectCoin(board, n, m);

    return 0;
}

void Nhap(int board[][MAX_N], int &n, int &m)
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> board[i][j];
}

int CollectCoin(int board[][MAX_N], int n, int m)
{
    int table[MAX_N][MAX_N];
    table[1][1] = board[1][1];
    for (int j = 2; j <= m; j++)
        table[1][j] = table[1][j - 1] + board[1][j];
    for (int i = 2; i <= n; i++)
    {
        table[i][1] = table[i - 1][1] + board[i][1];
        for (int j = 2; j <= m; j++)
            table[i][j] = max(table[i - 1][j], table[i][j - 1]) + board[i][j];
    }
    return table[n][m];
}
