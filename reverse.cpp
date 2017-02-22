#include <iostream>
using namespace std;

int input(unsigned i) 
{
	cin >> i;
	if (i != 0) {
		input(i);
		cout << i << " ";
	}
	return 0;
}

int main()
{
    unsigned number = 0;
	input(number);
		
	return 0;
}
