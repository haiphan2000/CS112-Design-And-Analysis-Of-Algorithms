#include <iostream>
#define MAX_N 1000
using namespace std;

void Nhap(int [], int &);
int ViTriMax(int [], int);
void XoaPhanTu(int [], int &, int);
void PickNumber(int [], int, int, int []);
int TinhTong(int [], int);

int main()
{
    int n;
    int array[MAX_N];
    int k;
    int solution[MAX_N];

    Nhap(array, n);
    cin >> k;
    PickNumber(array, n, k, solution);
    cout << TinhTong(solution, k);

    return 0;
}

void Nhap(int array[], int &n)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> array[i];
}

int ViTriMax(int array[], int n)
{
    int pos = 1;
    for (int i = 2; i <= n; i++)
        if (array[i] >array[pos])
            pos = i;
    return pos;
}

void XoaPhanTu(int array[], int &n, int pos)
{
    for (int i = pos; i <= n - 1; i++)
        array[pos] = array[pos + 1];
    n--;
}

void PickNumber(int array[], int n, int k, int solution[])
{
    for (int i = 1; i <= k; i++)
    {
        int pos = ViTriMax(array, n);
        solution[i] = array[pos];
        XoaPhanTu(array, n, pos);
    }
}

int TinhTong(int array[], int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum = sum + array[i];
    return sum;
}
