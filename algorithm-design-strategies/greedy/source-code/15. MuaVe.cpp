#include <iostream>
#include <algorithm>
#define MAX_N 100
using namespace std;

void Nhap1(int [], int &);
void Nhap2(int [], int);
int MuaVe(int [], int [], int);

int main()
{
    int n;
    int t[MAX_N];
    int p[MAX_N];

    Nhap1(t, n);
    Nhap2(p, n - 1);
    cout << MuaVe(t, p, n);
    return 0;
}

void Nhap1(int t[], int &n)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[i];
}

void Nhap2(int p[], int n)
{
    for (int i = 1; i <= n; i++)
        cin >> p[i];
}

int MuaVe(int t[], int p[], int n)
{
    int solution[MAX_N];
    solution[1] = t[1];
    solution[2] = min(t[1] + t[2], p[1]);
    for (int i = 3; i <= n; i++)
        solution[i] = min(t[i] + solution[i - 1], p[i - 1] + solution[i - 2]);
    return solution[n];
}
