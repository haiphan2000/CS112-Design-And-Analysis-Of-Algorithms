#include <iostream>
#include <algorithm>
#define MAX_N 1000
using namespace std;

void Nhap(int [], int &);
void Xuat(int [], int);
void OptimalStorage(int [], int);
int RetrievalTime(int [], int);

int main()
{
    int n;
    int length[MAX_N];

    Nhap(length, n);
    OptimalStorage(length, n);
    Xuat(length, n);
    cout << endl << RetrievalTime(length, n);

    return 0;
}

void Nhap(int length[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> length[i];
}

void Xuat(int length[], int n)
{
    for (int i = 0; i < n; i++)
        cout << length[i] << " ";
}

void OptimalStorage(int length[], int n)
{
    sort(length, length + n);
}

int RetrievalTime(int length[], int n)
{
    int sum = 0;
    int count = n;
    for (int i = 0; i < n; i++)
        sum = sum + length[i]*(count--);
    return sum;
}
