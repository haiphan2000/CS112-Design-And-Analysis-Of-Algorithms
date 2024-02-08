
#include <iostream>
#define MAX_N 1000
using namespace std;

void NhapMang(int [], int &);
void XuatMang(int [], int);
void HoanDoi(int [], int, int, int);
void ChuyenPhanTu(int [], int, int);

int main()
{
    int m;
    int n;
    int array[MAX_N];
    
    NhapMang(array, n);
    cin >> m;
    ChuyenPhanTu(array, m, n);
    XuatMang(array, n);

    return 0;
}

void NhapMang(int array[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> array[i];
}

void XuatMang(int array[], int n)
{
    for (int i = 0; i < n; i++)
        cout << array[i] << '\t';
}

void HoanDoi(int array[], int start_1, int start_2, int m)
{
    for (int i = 0; i < m; i++)
    {
        int temp = array[start_1 + i];
        array[start_1 + i] = array[start_2 + i];
        array[start_2 + i] = temp;
    }
}

void ChuyenPhanTu(int array[], int m, int n)
{
    if (m == 0 || m == n)
        return;
    if (m == n - m)
    {
        HoanDoi(array, 0, n - m, m);
        return;
    }
    if (m < n - m)
    {
        HoanDoi(array, 0, n - m, m);
        ChuyenPhanTu(array, m, n - m);
    }
    if (m > n - m)
    {
        HoanDoi(array, 0, m, n - m);
        ChuyenPhanTu(array + n - m, 2 * m - n, m);
    }
}
