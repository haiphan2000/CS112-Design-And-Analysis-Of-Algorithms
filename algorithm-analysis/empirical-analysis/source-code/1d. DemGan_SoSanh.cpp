#include <iostream>
#include <cmath>
using namespace std;

void Input4(long, long &, long &);

int main()
{
    long gan = 0;
    long so_sanh = 0;
    
    for (int i = 1; i <= 20; i++)
    {
        Input4(i, gan, so_sanh);
        cout << i << "\t" << gan << "\t" << so_sanh << endl;
    }
    
    return 0;
}

void Input4(long n, long &gan, long &so_sanh)
{
    long i = 1;
	long count = 0;
	gan = 2;
	so_sanh = 0;
	while (++so_sanh && i <= 3*n)
	{
		long x = 2*n - i;
		long y = i - n;
		long j = 1;
		gan = gan + 3;
		while (++so_sanh && j <= x)
		{
			if (++so_sanh && j >= n)
			{
				count = count - 1;
				gan++;
			}
			j = j + 1;
			gan++;
		}
		if (++so_sanh && y > 0)
			if (++so_sanh && x > 0)
			{
				count = count + 1;
				gan++;
			}
		i = i + 1;
		gan++;
	}
}