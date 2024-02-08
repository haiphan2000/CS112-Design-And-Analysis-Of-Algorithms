#include <iostream>
using namespace std;

#define MAX_N 100

struct Point
{
    double hoanh;
    double tung;
    int hang;
    int vi_tri;
};

void NhapDiem(Point &);
void HoanDoi(Point &, Point &);

struct Set
{
    int n;
    Point Diem[MAX_N];
};

Set TapHop;

void NhapTapHop();
void XuatHang();
int Partition_1(int, int);
void SapXepTangHoanhDo(int, int);
int Partition_2(int, int);
void SapXepTangViTri(int, int);
void TimHang(int, int);

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

int Partition_2(int left, int right)
{
    int mid = (left + right) / 2;
    if(TapHop.Diem[mid].vi_tri < TapHop.Diem[left].vi_tri)
        HoanDoi(TapHop.Diem[mid], TapHop.Diem[left]);
    if(TapHop.Diem[right].vi_tri < TapHop.Diem[left].vi_tri)
        HoanDoi(TapHop.Diem[right], TapHop.Diem[left]);
    if(TapHop.Diem[mid].vi_tri < TapHop.Diem[right].vi_tri)
        HoanDoi(TapHop.Diem[mid], TapHop.Diem[right]);
    double pivot = TapHop.Diem[right].vi_tri;
    int i = left - 1;
    for(int j = left; j < right; j++)
    {
        if(TapHop.Diem[j].vi_tri < pivot)
        {
            i = i + 1;
            HoanDoi(TapHop.Diem[i], TapHop.Diem[j]);
        }
    }
    HoanDoi(TapHop.Diem[i + 1], TapHop.Diem[right]);
    return i + 1;
}

void SapXepTangViTri(int left, int right)
{
    if(left < right)
    {
        int pivot = Partition_2(left, right);
        SapXepTangViTri(left, pivot - 1);
        SapXepTangViTri(pivot + 1, right);
    }
}

void TimHang(int left, int right)
{
    if(left == right)
        TapHop.Diem[left].hang = 0;
    else
    {
        int mid = (left + right) / 2;
        TimHang(left, mid);
        TimHang(mid + 1, right);
        for(int i = mid + 1; i <= right; i++)
            for(int j = left; j <= mid; j++)
                if(TapHop.Diem[i].tung > TapHop.Diem[j].tung)
                    (TapHop.Diem[i].hang)++;
    }
}