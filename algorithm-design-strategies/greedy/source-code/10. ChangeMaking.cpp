#include <iostream>
#include <climits>
#define MAX_N 100
using namespace std;

void Nhap(int [], int &);
int ChangeMaking(int [], int, int);

int main()
{
    int m;
    int d[MAX_N];
    int n;

    Nhap(d, m);
    cin >> n;
    cout << ChangeMaking(d, m, n);

    return 0;
}

void Nhap(int d[], int &m)
{
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> d[i];
}

int ChangeMaking(int d[], int m, int n)
{
    int table[MAX_N];
    table[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int temp = INT_MAX;
        int j = 1;
        while (j <= m && i >= d[j])
        {
            temp = min(table[i - d[j]], temp);
            j++;
        }
        table[i] = temp + 1;
    }
    return table[n];
}
