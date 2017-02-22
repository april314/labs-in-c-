/* GCD(a,b)=GCD(b,a mod b)
GCD(0,a)=a
GCD(a,b)=GCD(b,a) */

#include <iostream>
using namespace std;

unsigned gcd(unsigned a, unsigned b)
{
    if (a < b) {
		int temp = a;
		a = b;
		b = temp;
	}
	if (a == b || b == 0)
		return a;
	return gcd(b, a%b);
}

int main()
{
    cout << gcd(100, 100);
		
	return 0;
}
