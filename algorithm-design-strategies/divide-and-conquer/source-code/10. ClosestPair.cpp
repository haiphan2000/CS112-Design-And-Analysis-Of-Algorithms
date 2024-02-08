#include <iostream>
#include <cmath>
using namespace std;

#define MAX_N 100

struct Point
{
    double hoanh;
    double tung;
};

void NhapDiem(Point &);
void HoanDoi(Point &, Point &);
double KhoangCach(Point, Point);

int n;
Point Diem[MAX_N];

void NhapTapHop();
void XuatHang();
int Partition(int, int);
void SapXepTangHoanhDo(int, int);
int ClosestPair();

int main()
{
    NhapTapHop();
    SapXepTangHoanhDo(0, TapHop.n - 1);
    TimHang(0, TapHop.n - 1);
    XuatHang();
    return 0;
}

void NhapDiem(Point &P)
{
    cin >> P.hoanh >> P.tung;
}

void HoanDoi(Point &P, Point &Q)
{
    swap(P.hoanh, Q.hoanh);
    swap(P.tung, Q.tung);
    swap(P.hang, Q.hang);
    swap(P.vi_tri, Q.vi_tri);
}

double KhoangCach(Point P, Point Q)
{
    return sqrt( (P.hoanh - Q.hoanh) * (P.hoanh - Q.hoanh) + (P.tung - Q.tung) * (P.tung - Q.tung) );
}

void NhapTapHop()
{
    cin >> TapHop.n;
    for(int i = 0; i < TapHop.n; i++)
    {
        NhapDiem(TapHop.Diem[i]);
        TapHop.Diem[i].vi_tri = i;
    }
}

void XuatHang()
{
    SapXepTangViTri(0, TapHop.n - 1);
    for(int i = 0; i < TapHop.n; i++)
        cout << TapHop.Diem[i].hang << " ";
}

int Partition_1(int left, int right)
{
    int mid = (left + right) / 2;
    if(TapHop.Diem[mid].hoanh < TapHop.Diem[left].hoanh)
        HoanDoi(TapHop.Diem[mid], TapHop.Diem[left]);
    if(TapHop.Diem[right].hoanh < TapHop.Diem[left].hoanh)
        HoanDoi(TapHop.Diem[right], TapHop.Diem[left]);
    if(TapHop.Diem[mid].hoanh < TapHop.Diem[right].hoanh)
        HoanDoi(TapHop.Diem[mid], TapHop.Diem[right]);
    double pivot = TapHop.Diem[right].hoanh;
    int i = left - 1;
    for(int j = left; j < right; j++)
    {
        if(TapHop.Diem[j].hoanh < pivot)
        {
            i = i + 1;
            HoanDoi(TapHop.Diem[i], TapHop.Diem[j]);
        }
    }
    HoanDoi(TapHop.Diem[i + 1], TapHop.Diem[right]);
    return i + 1;
}

void SapXepTangHoanhDo(int left, int right)
{
    if(left < right)
    {
        int pivot = Partition_1(left, right);
        SapXepTangHoanhDo(left, pivot - 1);
        SapXepTangHoanhDo(pivot + 1, right);
    }
}

int ClosestPair(Point P[], int n)
{
    if(n == 1)
        return 0;
    int mid = n / 2;
    Point MidPoint = Diem[mid];
    
    float dist_left = ClosestPair(P, mid);  
    float dist_right = ClosestPair(P + mid, n - mid);
    float d = min(dl, dr);
    Point strip[n];  
    int j = 0;  
    for (int i = 0; i < n; i++)  
        if (abs(P[i].x - midPoint.x) < d)  
            strip[j] = P[i], j++;  
  
    // Find the closest points in strip.  
    // Return the minimum of d and closest  
    // distance is strip[]  
    return min(d, stripClosest(strip, j, d) );
}