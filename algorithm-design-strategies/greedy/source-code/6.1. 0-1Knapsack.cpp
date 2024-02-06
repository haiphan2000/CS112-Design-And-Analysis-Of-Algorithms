#include <iostream>
#include <algorithm>
#define MAX_N 100
using namespace std;

void Nhap(int [], int [], int &, int &);
int Knapsack(int [], int [], int, int);

int main()
{
    int n;
    int price[MAX_N];
    int weight[MAX_N];
    int capacity;

    Nhap(price, weight, n, capacity);
    cout << Knapsack(price, weight, n, capacity);

    return 0;
}

void Nhap(int price[], int weight[], int &n, int &capacity)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> price[i] >> weight[i];
    }
    cin >> capacity;
}

int Knapsack(int price[], int weight[], int n, int capacity)
{
    int solution[MAX_N][MAX_N];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
                solution[i][j] = 0;
            else
                if (j - weight[i] >= 0)
                    solution[i][j] = max(solution[i - 1][j], price[i] + solution[i - 1][j - weight[i]]);
                else
                    solution[i][j] = solution[i - 1][j];
        }
    return solution[n][capacity];
}
