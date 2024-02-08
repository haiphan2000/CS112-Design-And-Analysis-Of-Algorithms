#include <iostream>
#define MAX_N 1000
using namespace std;

int n;
int array[MAX_N];

void NhapMang();
void XuatMang();
int Partition(int, int);
void QuickSort(int, int);

int main()
{
    NhapMang();
    QuickSort(0, n - 1);
    XuatMang();

    return 0;
}

void NhapMang()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> array[i];
}

void XuatMang()
{
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
}

int Partition(int left, int right)
{
    int pivot = array[right];
    int i = left - 1;
    for(int j = left; j < right; j++)
    {
        if(array[j] <= pivot)
        {
            i = i + 1;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[right]);
    return i + 1;
}

void QuickSort(int left, int right)
{
    if(left < right)
    {
        int pivot = Partition(left, right);
        QuickSort(left, pivot - 1);
        QuickSort(pivot + 1, right);
    }
}
