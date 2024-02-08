#include <iostream>
#include <vector>
#define MAX_N 1000
using namespace std;

int n;
int array[MAX_N];

void NhapMang()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> array[i];
}

int MergeAndCount(int left, int mid, int right)
{
    int count = 0;
    int i = left;
    int j = mid;
    int temp[MAX_N];
    int k = 0;
    while ((i <= mid - 1) && (j <= right))
    {
        if (array[i] < array[j])
            temp[k++] = array[i++];
        else
        {
            temp[k++] = array[j++];
            count = count + (mid - i);
        }
    }
    while (i <= mid - 1) 
        temp[k++] = array[i++]; 
    while (j <= right) 
        temp[k++] = array[j++]; 
    for (int i = 0; i < k; i++)
        array[left + i] = temp[i];
    return count;
}

int SortAndCount(int left, int right)
{
    if (left == right)
        return 0;
    int mid = (left + right) / 2;
    int count_left = SortAndCount(left, mid);
    int count_right = SortAndCount(mid + 1, right);
    int count_merge = MergeAndCount(left, mid + 1, right);
    return count_left + count_right + count_merge;
}


int main()
{
    NhapMang();
    cout << SortAndCount(0, n - 1);
    return 0;
}