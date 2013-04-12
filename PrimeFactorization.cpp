#include<iostream>

using namespace std;

unsigned long square(int i);

void prime_factorization(long x)
{
  long i; /* counter */
	long c; /* remaining product to factor */
	c = x;
	if(x == 0 || x == 1 || x == 2 || x == 3)
	{
		cout << x << endl;
		return;
	}
	while ((c % 2) == 0)
	{
		cout << 2 << "x";
		c = c / 2;
	}
	i = 3;
	while (square(i) <= c)
	{
		if ((c % i) == 0)
		{
			cout << i  << "x";
			c = c / i;
		} else
			i = i + 2;
	}
	if (c > 1)
	{
		if(c == x)
			cout << x << "is prime ";
		cout << c << endl;
	}
}

const int MAX_INTEGER = 5000;
void primeFacDriver()
{
	for(int i = 0; i <= MAX_INTEGER; i++)
	{
		cout << "prime_factorization(" << i << ") = " ;
		prime_factorization(i);
		cout << endl;
	}
}
