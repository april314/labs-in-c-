//operator[] overload for calls like string[1][4] - returns a substring from 1 to 4 symbols
#include <cstddef> // size_t
#include <cstring>
#include <iostream>

int ipos = -1;
struct String;
struct ChildString;

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	String(const String &other);
    String &operator=(const String &other);
	~String();

	void append(const String &other);
	
	ChildString operator[](int i) const;
	
	friend std::ostream& operator<< (std::ostream& stream, const String& str);
	
	size_t size;
	char *str;      
};

struct ChildString {
	ChildString(const char *st = "") {
		strcpy(str,st);
	}
	
	friend std::ostream& operator<< (std::ostream& stream, const ChildString& str);
	
	String operator[] (int j) const;

	char str[128];
};

String::String(const char *str)
{
	size = strlen(str);
	char * stmp = new char[size+1];
	strcpy(stmp,str);
	this->str = stmp;
}

String::String(const String &other)
{
	size = strlen(other.str);
	char * stmp = new char[size+1];
	strcpy(stmp,other.str);
	this->str = stmp;
}
    
String & String::operator=(const String &other)
{
	if (this != &other) {
		delete [] str;
		size = strlen(other.str);
		char * stmp = new char[size+1];
		strcpy(stmp,other.str);
		this->str = stmp;
	}
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

void String::append(String const &other)
{
	size_t new_size = (size + other.size + 1);
	char * stmp = new char[new_size];
	strcpy(stmp, str);
	strcat(stmp, other.str);
	delete [] str;
	str = stmp;
	size = new_size - 1;
}

ChildString String::operator[](int i) const {
	std::cout << "StrOp[] called\n";
	if (i < 0 || i > this->size)
		return "";
	ipos = i;
	std::cout << ipos << std::endl;
	size_t newsz = this->size-i+1;
	char * tmpst = new char[newsz];
	int c = 0;
	for (; c < newsz; ++c) {
		tmpst[c] = this->str[c+i];
	}
	tmpst[c] = '\0';
	ChildString tmp(tmpst);
	std::cout << tmp;
	delete [] tmpst;
	return tmp;
}

std::ostream& operator<< (std::ostream& stream, const String& str)
{
	std::cout << str.str << std::endl;
	std::cout << str.size << std::endl;
	return stream;
}

std::ostream& operator<< (std::ostream& stream, const ChildString& str)
{
	std::cout << str.str << std::endl;
	return stream;
}

String ChildString::operator[] (int j) const {
	std::cout << "ChildStrOp[] called\n";
	if (j <= ipos)
		return "";
	size_t newsz = j-ipos + 1;
	std::cout << newsz << std::endl;
	char * tmpst = new char[newsz];
	int c = 0;
	std::cout << this->str << std::endl;
	for (; c < newsz-1; ++c) {
		tmpst[c] = this->str[c];
	}
	tmpst[c] = '\0';
	std::cout << tmpst << std::endl;
	String tmp(tmpst);
	std::cout << tmp;
	ipos = -1;
	delete [] tmpst;
	return tmp;
}

int main() {
	
	String const hello("hello");
	std::cout << hello << std::endl;
	String const hell = hello[0][4]; // теперь в hell хранится подстрока "hell"
	std::cout << hell << std::endl;
	String const ell  = hello[1][4]; // теперь в ell хранится подстрока "ell"
	std::cout << ell << std::endl;
	
	return 0;
}
