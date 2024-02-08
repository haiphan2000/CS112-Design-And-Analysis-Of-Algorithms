#include <iostream>
#include <cmath>
using namespace std;

void Input3(long, long &, long &);

int main()
{
    float x = 2;
    long gan = 0;
    long so_sanh = 0;
    
    for (int i = 1; i <= 20; i++)
    {
        Input3(i, gan, so_sanh);
        cout << i << "\t" << gan << "\t" << so_sanh << endl;
    }
    
    return 0;
}

void Input3(long n, long &gan, long &so_sanh)
{
	long i = 1;
	long ret = 0;
	float s = 0;
	gan = 3;
	so_sanh = 0;
	while (++so_sanh && i <= n)
	{
	    long j = 1;
		s = s + 1/i;
		gan = gan + 2;
		while (++so_sanh && j <= s)
		{
		    ret = ret + i*j;
			j = j + 1;
			gan = gan + 2;
		}
		i = i + 1;
		gan = gan + 1;
	}
}