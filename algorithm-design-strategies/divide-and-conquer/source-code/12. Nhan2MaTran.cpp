#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> matrix;

void NhapMaTran(matrix &, int);
void XuatMaTran(matrix, int);
void Cong(matrix, matrix, matrix &, int);
void Tru(matrix, matrix, matrix &, int);
void ChiaBlock(matrix &, matrix &, matrix &, matrix &, matrix, int);
void GhepBlock(matrix, matrix, matrix, matrix, matrix &, int);
void Nhan(matrix, matrix, matrix &, int);

int main()
{
    int n;
    cin >> n;
    
    vector<int> size (n);
    matrix matrixA (n, size);
    matrix matrixB (n, size);
    matrix matrixC (n, size);
    NhapMaTran(matrixA, n);
    NhapMaTran(matrixB, n);
    Nhan(matrixA, matrixB, matrixC, n);
    XuatMaTran(matrixC, n);
    

    return 0;
}

void NhapMaTran(matrix &matrixA, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            matrixA[i][j] = x;
        }
    }
}

void XuatMaTran(matrix matrixA, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrixA[i][j] << '\t';
        cout << endl;
    }
}

void Cong(matrix matrixA, matrix matrixB, matrix &matrixC, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
}

void Tru(matrix matrixA, matrix matrixB, matrix &matrixC, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
}

void ChiaBlock(matrix &A00, matrix &A01, matrix &A10, matrix &A11, matrix matrixA, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            A00[i][j] = matrixA[i][j];
            A01[i][j] = matrixA[i][j + n];
            A10[i][j] = matrixA[i + n][j];
            A11[i][j] = matrixA[i + n][j + n];
        }
}

void GhepBlock(matrix A00, matrix A01, matrix A10, matrix A11, matrix &matrixA, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            matrixA[i][j] = A00[i][j];
            matrixA[i][j + n] = A01[i][j];
            matrixA[i + n][j] = A10[i][j];
            matrixA[i + n][j + n] = A11[i][j];
        }
}

void Nhan(matrix matrixA, matrix matrixB, matrix &matrixC, int n)
{
    if (n == 1)
    {
        matrixC[0][0] = matrixA[0][0] * matrixB[0][0];
        return;
    }
    int new_n = n / 2;
    vector<int> size (new_n);
    matrix
        A00(new_n, size), A01(new_n, size), A10(new_n, size), A11(new_n, size),
        B00(new_n, size), B01(new_n, size), B10(new_n, size), B11(new_n, size),
        C00(new_n, size), C01(new_n, size), C10(new_n, size), C11(new_n, size),
        P1(new_n, size), P2(new_n, size), P3(new_n, size), P4(new_n, size),
        P5(new_n, size), P6(new_n, size), P7(new_n, size),
        temp1(new_n, size), temp2(new_n, size);
    
    ChiaBlock(A00, A01, A10, A11, matrixA, new_n);
    ChiaBlock(B00, B01, B10, B11, matrixB, new_n);
    
    Cong(A00, A11, temp1, new_n);   // a00 + a11
    Cong(B00, B11, temp2, new_n);   // b00 + b11
    Nhan(temp1, temp2, P1, new_n);  // P1 = (a00 + a11) * (b00 + b11)
    
    Cong(A10, A11, temp1, new_n);   // a10 + a11
    Nhan(temp1, B00, P2, new_n);    // P2 = (a10 + a11) * b00
    
    Tru(B01, B11, temp2, new_n);    // b01 - b11
    Nhan(A00, temp2, P3, new_n);    // P3 = a00 * (b01 - b11)
    
    Tru(B10, B00, temp2, new_n);    // b10 - b00
    Nhan(A11, temp2, P4, new_n);    // P4 = a11 * (b10 - b00)
    
    Cong(A00, A01, temp1, new_n);   // a00 + a01
    Nhan(temp1, B11, P5, new_n);    // P5 = (a00 + a01) * b11

    Tru(A10, A00, temp1, new_n);    // a10 - a00
    Cong(B00, B01, temp2, new_n);   // b00 + b01
    Nhan(temp1, temp2, P6, new_n);  // P6 = (a10 - a00) * (b00 + b01)
    
    Tru(A01, A11, temp1, new_n);    // a01 - a11
    Cong(B10, B11, temp2, new_n);   // b10 + b11
    Nhan(temp1, temp2, P7, new_n);  // P7 = (a01 - a11) * (b10 + b11)
    
    Cong(P1, P4, temp1, new_n);     // P1 + P4
    Cong(temp1, P7, temp2, new_n);  // P1 + P4 + P7
    Tru(temp2, P5, C00, new_n);     // C00 = P1 + P4 - P5 + P7
    
    Cong(P3, P5, C01, new_n);       // C01 = P3 + P5
    
    Cong(P2, P4, C10, new_n);       // C10 = P2 + P4
    
    Cong(P1, P3, temp1, new_n);     // P1 + P3
    Cong(temp1, P6, temp2, new_n);   // P1 + P3 + P6
    Tru(temp1, P2, C11, new_n);  // C11 = P1 + P3 - P2 + P6
    
    GhepBlock(C00, C01, C10, C11, matrixC, new_n);
}
