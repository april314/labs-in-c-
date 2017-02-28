#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
#include <iostream>

struct String {

    /* Реализуйте этот конструктор */
	explicit String(const char *str = "");
	String(size_t n, char c);
	~String();
	void append(String &other);

	size_t size;
	char *str;
};

String::String(const char *str)
{
	size = strlen(str);
	char * stmp = new char[size+1];
	strcpy(stmp,str);
	this->str = stmp;
}

//filling constructor
String::String(size_t n, char c)
{
	size = n;
	char * stmp = new char[size+1];
	for (size_t i = 0; i != size; ++i) {
		stmp[i] = c;
	}
	stmp[size] = '\0';
	str = stmp;
}

String::~String()
{
	delete [] str;
}

void String::append(String &other)
{
	size_t new_size = (size + other.size + 1);
	char * stmp = new char[new_size];
	strcpy(stmp, str);
	strcat(stmp, other.str);
	delete [] str;
	str = stmp;
	size = new_size - 1;
}

int main()
{
	String s1(6, 'f');
	String s2("Mary");

	s1.append(s2); // теперь s1 хранит "Hello, world!"
	std::cout << s1.str << s1.size << std::endl;
	
	s1.append(s1);
	std::cout << s1.str << s1.size << std::endl;
	
	s1.append(s2); // теперь s1 хранит "Hello, world!"
	std::cout << s1.str << s1.size << std::endl;
	
	s2.append(s1); // теперь s1 хранит "Hello, world!"
	std::cout << s2.str << s2.size << std::endl;
	
	String s("");
	String s3;
	s.append(s3);
	std::cout << s.str << s.size << std::endl;
	
	return 0;
}
