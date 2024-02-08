#include <iostream>
using namespace std;

void Nhap(float &, int &);
void ChiaThuoc(float, float, float, int);

int main()
{
    float length;
    int height;

    Nhap(length, height);
    ChiaThuoc(0, length, length, height);

    return 0;
}

void Nhap(float &length, int &height)
{
    cin >> length >> height;
}

void ChiaThuoc(float left, float right, float length, int height)
{
    if (height == 0)
        return;
    float mid = (left + right) / 2;
    ChiaThuoc(left, mid - 1, length / 2, height - 1);
    cout << mid << '\t' << height << endl;
    ChiaThuoc(mid + 1, right, length / 2, height - 1);
}
