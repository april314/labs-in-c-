#include <iostream>
using namespace std;

int main()
{
    char c = '\0';
	bool space = false;
	
    while (cin.get(c)) {
		if (c != ' ') {
			cout << c;
			space = false;
		}
		else if (c = ' ') {
			if (!space) {
				space = true;
				cout << c;
			}
		}	
    }

	return 0;
}
