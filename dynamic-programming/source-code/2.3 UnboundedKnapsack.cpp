#include <iostream>
#include <algorithm>
#define MAX_N 100
using namespace std;

struct item
{
    double price;
    double weight;

    friend istream& operator >> (istream &, item &);
};

void Nhap(item [], int &);
bool SoSanh(item, item);
void SapXep(item [], int);
void UnBoundedKnapsack(item [], int, int, int []);
double TinhTong(item [], int, int []);

int main()
{
    int n;
    item do_vat[MAX_N];
    int capacity;
    int k = 0;
    int so_luong[MAX_N];

    Nhap(do_vat, n);
    cin >> capacity;
    UnBoundedKnapsack(do_vat, n, capacity, so_luong);
    cout << TinhTong(do_vat, n, so_luong);

    return 0;
}

istream& operator >> (istream &is, item &do_vat)
{
    cin >> do_vat.price >> do_vat.weight;
}

void Nhap(item do_vat[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> do_vat[i];
}

bool SoSanh(item do_vat1, item do_vat2)
{
    double temp1 = do_vat1.price / do_vat1.weight;
    double temp2 = do_vat2.price / do_vat2.weight;
    return (temp1 > temp2);
}

void SapXep(item do_vat[], int n)
{
    sort(do_vat, do_vat + n, SoSanh);
}

void UnBoundedKnapsack(item do_vat[], int n, int capacity, int so_luong[])
{
    SapXep(do_vat, n);
    for (int i = 0; i < n; i++)
        while (do_vat[i].weight <= capacity)
        {
            so_luong[i]++;
            capacity = capacity - do_vat[i].weight;
        }
}

double TinhTong(item do_vat[], int n, int so_luong[])
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + do_vat[i].price * so_luong[i];
    return sum;
}
