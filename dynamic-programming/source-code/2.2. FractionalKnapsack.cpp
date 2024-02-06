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
void FractionalKnapsack(item [], int, int, double []);
double TinhTong(item [], int, double []);

int main()
{
    int n;
    item do_vat[MAX_N];
    int capacity;
    int k = 0;
    double fraction[MAX_N];

    Nhap(do_vat, n);
    cin >> capacity;
    FractionalKnapsack(do_vat, n, capacity, fraction);
    cout << TinhTong(do_vat, n, fraction);

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

void FractionalKnapsack(item do_vat[], int n, int capacity, double fraction[])
{
    SapXep(do_vat, n);
    int i;
    for (i = 0; i < n; i++)
        if (do_vat[i].weight > capacity)
            break;
        else
        {
            fraction[i] = 1;
            capacity = capacity - do_vat[i].weight;
        }
    if (i < n)
        fraction[i] = capacity / do_vat[i].weight;
}

double TinhTong(item do_vat[], int n, double fraction[])
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + do_vat[i].price * fraction[i];
    return sum;
}
