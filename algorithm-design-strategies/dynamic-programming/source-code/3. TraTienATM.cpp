#include <iostream>
#define MAX_N 1000
using namespace std;

int loai_tien[4] = { 500, 200, 100, 50 };

void TraTienATM(int, int [], int &);
int TinhTong(int [], int);

int main()
{
    int n;
    int k = 0;
    int tien_thoi[MAX_N];

    cin >> n;
    TraTienATM(n, tien_thoi, k);
    cout << k;

    return 0;
}

void TraTienATM(int n, int tien_thoi[], int &k)
{
    int i = 0;
    while (n != 0)
    {
        while (n < loai_tien[i])
        {
            i++;
        }
        n = n - loai_tien[i];
        tien_thoi[k++] = loai_tien[i];
    }
}
