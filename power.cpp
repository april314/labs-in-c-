// определите только функцию power, где
//    x - число, которое нужно возвести в степень
//    p - степень, в которую нужно возвести x
//
#include <iostream>
using namespace std;
int power(int x, unsigned p);

int main()
{
	cout << power(2,0) << endl;
	return 0;
}

int power(int x, unsigned p) {
    int answer = 1;
    /* считаем answer */
	for (unsigned i = 1; i <= p; ++i) {
		answer *= x;
	}
    return answer;
}
