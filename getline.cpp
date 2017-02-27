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

char * getline()
{
	int size = 12, old_size = size;
	char * line = new char[size];
	int i = 0;
	char c = 0;
	
	while (std::cin.get(c) && c != '\n') {
		if (i == (size-1)) {
			old_size = size;
			size += 10;
			line = resize(line, old_size, size);
		}
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return line;
}

int main()
{
	char * str = getline();
	cout << str << endl;
	
	delete [] str;
	str = 0;
	
	return 0;
}
