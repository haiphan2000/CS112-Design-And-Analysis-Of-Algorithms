#include <iostream>
#define MAX_N 1000
using namespace std;

int n;
int array[MAX_N];

void NhapMang();
void XuatMang();
void Merge(int, int, int);
void MergeSort(int, int);

int main()
{
    NhapMang();
    MergeSort(0, n - 1);
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

void Merge(int left, int mid, int right)
{
    int i = left;
    int j = mid;
    int temp[MAX_N];
    int k = 0;
    while ((i <= mid - 1) && (j <= right))
    {
        if (array[i] < array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }
    while (i <= mid - 1)
        temp[k++] = array[i++];
    while (j <= right)
        temp[k++] = array[j++];
    for (int i = 0; i < k; i++)
        array[left + i] = temp[i];
}

void MergeSort(int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(left, mid);
        MergeSort(mid + 1, right);
        Merge(left, mid + 1, right);
    }
}
