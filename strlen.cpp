#include <iostream>
using namespace std;

unsigned strlen(const char *str)
{
	unsigned len = 0;
	while (str[len] != '\0') {
		len++;
	}
	return len;
}

int main()
{
	const char * str = "Hello";	
	cout << strlen(str) << endl;
	return 0;
}
