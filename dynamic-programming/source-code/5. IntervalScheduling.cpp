#include <iostream>
#include <algorithm>
#define MAX_N 100
using namespace std;

struct activity
{
    int start;
    int finish;

    friend istream& operator >> (istream &, activity &);
    friend ostream& operator << (ostream &, const activity &);
};

bool KetThucSomHon(activity, activity);

void Nhap(activity [], int &);
void Xuat(activity [], int);
void SapXep(activity [], int);
void IntervalScheduling(activity [], int, activity [], int &);

int main()
{
    int n;
    activity list[MAX_N];
    int k = 0;
    activity solution[MAX_N];

    Nhap(list, n);
    IntervalScheduling(list, n, solution, k);
    Xuat(solution, k);

    return 0;
}

bool KetThucSomHon(activity act1, activity act2)
{
    return (act1.finish < act2.finish);
}

istream& operator >> (istream &is, activity &act)
{
    is >> act.start >> act.finish;
}

ostream& operator << (ostream &os, const activity &act)
{
    os << act.start << " " << act.finish;
}

void Nhap(activity list[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> list[i];
}

void Xuat(activity list[], int n)
{
    for (int i = 0; i < n; i++)
        cout << list[i] << endl;
}

void SapXep(activity list[], int n)
{
    sort(list, list + n, KetThucSomHon);
}

void IntervalScheduling(activity list[], int n, activity solution[], int &k)
{
    SapXep(list, n);
    int prev_finish = 0;
    for (int i = 0; i < n; i++)
        if (list[i].start >= prev_finish)
        {
            solution[k++] = list[i];
            prev_finish = list[i].finish;
        }
}
