#include <iostream>
#include <string>
#define MAX_N 1000
using namespace std;

int LCSLength(string, string, int [][MAX_N]);

int main()
{
    string X;
    string Y;
    int position[MAX_N][MAX_N];

    cin >> X >> Y;
    cout << LCSLength(X, Y, position);

    return 0;
}

int LCSLength(string X, string Y, int position[][MAX_N])
{
    int table[MAX_N][MAX_N];
    int m = X.length();
    int n = Y.length();
    for (int i = 1; i <= m; i++)
        table[i][0] = 0;
    for (int j = 0; j <= n; j++)
        table[0][j] = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                table[i][j] = table[i - 1][j - 1] + 1;
                position[i][j] = 1;
            }
            else
                if (table[i - 1][j] > table[i][j - 1])
                {
                    table[i][j] = table[i - 1][j];
                    position[i][j] = 2;
                }
                else
                {
                    table[i][j] = table[i][j - 1];
                    position[i][j] = 3;
                }
        }
    return table[m][n];
}