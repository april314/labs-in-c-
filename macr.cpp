#define MAX(x, y, r) { int arg1 = (x); int arg2 = (y); r = arg1 > arg2 ? arg1 : arg2; } /* присваивает r максимум из x и y */

#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	int b = 20;
	int c = 0;
	MAX(a, b, c); // теперь c равно 20
	cout << c << endl;
	MAX(a, ++b, c); //21
	cout << c << endl;
	return 0;
}
