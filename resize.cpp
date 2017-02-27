#include <iostream>
using namespace std;

char * resize(const char *str, unsigned size, unsigned new_size)
{
	char * new_str = new char[new_size];
	if (size < new_size) {
		for (int i = 0; i < size; i++) {
			new_str[i] = str[i];
		}
	}
	else {
		for (int i = 0; i < new_size; i++) {
			new_str[i] = str[i];
		}
	}
	delete [] str;
	str = 0;
	return new_str;
}

int main()
{
	unsigned old_sz = 6, new_sz = 10;
	char * str = new char[old_sz];
	int i = 0;
	for (; i < old_sz-1; i++) {
		str[i] = i + 78;
	}
	str[i] = '\0';
	cout << str << endl;
	
	str = resize(str, old_sz, new_sz);
	
	delete [] str;
	str = 0;
	
	return 0;
}
