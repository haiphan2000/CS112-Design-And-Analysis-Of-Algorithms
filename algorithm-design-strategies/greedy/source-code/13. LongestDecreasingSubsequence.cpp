#include <iostream>
#define MAX_N 1000
using namespace std;

void Nhap(int [], int &);
int LDSLength(int [], int);

int main()
{
    int n;
    int array[MAX_N];

    Nhap(array, n);
    cout << LDSLength(array, n);

    return 0;
}

void Nhap(int array[], int &n)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> array[i];
}

int LDSLength(int array[], int n)
{
    int max = 0;
    int solution[MAX_N];
    for (int i = 1; i <= n; i++)
    {
        solution[i] = 1;
        for (int j = 1; j < i; j++)
            if (array[i] < array[j] && solution[i] < solution[j] + 1)
                solution[i] = solution[j] + 1;
    }
    for (int i = 1; i <= n; i++)
        if (max < solution[i])
            max = solution[i];
    return max;
}
