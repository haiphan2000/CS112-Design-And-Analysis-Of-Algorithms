#include <iostream>
#include <cmath>
using namespace std;

void Nhap(int &, int &, int &);
int TachNuaDau(int, int);
int TachNuaCuoi(int, int);
int LuyThua10(int, int);
int Nhan(int, int, int);

int main()
{
    int n;
    int A;
    int B;
    
    Nhap(A, B, n);
    cout << Nhan(A, B, n);
    
    return 0;
}

void Nhap(int &A, int &B, int &n)
{
    cin >> n >> A >> B;
}

int TachNuaDau(int so, int n)
{
    return so / LuyThua10(1, n);
}

int TachNuaSau(int so, int n)
{
    return so % LuyThua10(1, n);
}

int LuyThua10(int so, int n)
{
    return so * pow(10, n);
}

int Nhan(int A, int B, int n)
{
    if (n == 1)
        return A * B;
    int A1 = TachNuaDau(A, n/2);
    int A0 = TachNuaSau(A, n/2);
    int B1 = TachNuaDau(B, n/2);
    int B0 = TachNuaSau(B, n/2);
    int C0 = Nhan(A0, B0, n/2);
    int C2 = Nhan(A1, B1, n/2);
    int C1 = Nhan(A1 + A0, B1 + B0, n/2) - (C2 + C0);
    return LuyThua10(C2, n) + LuyThua10(C1, n/2) + C0;
}