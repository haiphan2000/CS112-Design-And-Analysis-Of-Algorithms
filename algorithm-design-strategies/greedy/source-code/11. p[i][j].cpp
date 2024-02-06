#include <iostream>
#define MAX_N 100
using namespace std;

double Tinh(double [][MAX_N], int, int);

int main()
{
    int m;
    int n;
    double p[MAX_N][MAX_N];

    cin >> m >> n;
    cout << Tinh(p, m, n);

    return 0;
}

double Tinh(double p[][MAX_N], int m, int n)
{
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
                p[i][j] = 1;
            else
                if (j == 0)
                    p[i][j] = 0;
                else
                    p[i][j] = 0.5 * (p[i - 1][j] + p[i][j - 1]);
        }
    return p[m][n];
}
