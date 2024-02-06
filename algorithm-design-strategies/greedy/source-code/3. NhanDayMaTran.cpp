#include <iostream>
#include <climits>
#define MAX_N 1000
using namespace std;

void Nhap(int [], int &);
int ChiPhiNhanNhoNhat(int [], int, int [][MAX_N]);

int main()
{
    int n;
    int kich_thuoc[MAX_N];
    int min_cost[MAX_N][MAX_N];

    Nhap(kich_thuoc, n);
    cout << ChiPhiNhanNhoNhat(kich_thuoc, n, min_cost);

    return 0;
}

void Nhap(int kich_thuoc[], int &n)
{
    cin >> n;
    cin >> kich_thuoc[0] >> kich_thuoc[1];
    int temp1;
    int temp2;
    for (int i = 1; i < n; i++)
    {
        cin >> temp1 >> temp2;
        kich_thuoc[i + 1] = temp2;
    }
}

int ChiPhiNhanNhoNhat(int kich_thuoc[], int n, int min_cost[][MAX_N])
{
    for (int i = 1; i <= n; i++)
        min_cost[i][i] = 0;
    for (int d = 1; d < n; d++)
        for (int i = 1; i <= n - d; i++)
        {
            int j = i + d;
            min_cost[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int temp = min_cost[i][k] + min_cost[k + 1][j] + kich_thuoc[i - 1] * kich_thuoc[k] * kich_thuoc[j];
                if (temp < min_cost[i][j])
                    min_cost[i][j] = temp;
            }
        }
    return min_cost[1][n];
}