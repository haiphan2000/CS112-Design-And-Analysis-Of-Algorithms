#include <iostream>
#define MAX_N 100
using namespace std;

int n;
int array[MAX_N];

bool KiemTraChinhPhuong(int);
void NhapMang();
void XuatChinhPhuong(int, int);

int main()
{
    NhapMang();
    XuatChinhPhuong(0, n - 1);
    
    return 0;
}

void NhapMang()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> array[i];
}

bool KiemTraChinhPhuong(int so)
{
    for (int i = 1; i <= so/2; i++)
        if (i*i == so)
            return true;
    return false;
}

void XuatChinhPhuong(int left, int right)
{
    if (left == right)
    {
        if (KiemTraChinhPhuong(array[left]) == true)
            cout << array[left] << '\t';
        return;
    }
    int mid = (left + right) / 2;
    XuatChinhPhuong(left, mid);
    XuatChinhPhuong(mid + 1, right);
}