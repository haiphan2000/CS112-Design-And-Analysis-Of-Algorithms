#include <iostream>
#include <algorithm>
#define MAX_N 1000
using namespace std;

void Nhap(int [], int [], int &, int &);
int UnBoundedKnapsack(int [], int [], int, int);

int main()
{
    int n;
    int price[MAX_N];
    int weight[MAX_N];
    int capacity;

    Nhap(price, weight, n, capacity);
    cout << UnBoundedKnapsack(price, weight, n, capacity);

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

int UnBoundedKnapsack(int price[], int weight[], int n, int capacity)
{
    int solution[MAX_N];
    solution[0] = 0;
    for (int i = 1; i <= capacity; i++)
    {
        for (int j = 1; j <= n; j++)
            if (weight[j] <= i)
                solution[i] = max(solution[i], solution[i - weight[j]] + price[j]);
    }
    return solution[capacity];
}
