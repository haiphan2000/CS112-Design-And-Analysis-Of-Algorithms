#include <iostream>
#include <cmath>
using namespace std;

void Input2(float, long, long &, long &);

int main()
{
    float x = 2;
    long gan = 0;
    long so_sanh = 0;
    
    for (int i = 1; i <= 20; i++)
    {
        Input2(x, i, gan, so_sanh);
        cout << i << "\t" << gan << "\t" << so_sanh << endl;
    }
    
    return 0;
}

void Input2(float x, long n, long &gan, long &so_sanh)
{
    long i = 1;
    float z = 0;
    gan = 2;
    so_sanh = 0;
	while (++so_sanh && i <= n)
	{
	    long j = 1;
	    float t = 1;
	    gan = gan + 2;
		while (++so_sanh && j <= i*i*i)
		{
		    t = t*x;
			j = j + 1;
			gan = gan + 2;
		}
		z = z + i*t;
		i = 2*i;
		gan = gan + 2;
	}
}