#include <iostream>
using namespace std;

int logg(unsigned a);
int power2(unsigned p);

int main()
{
    unsigned T = 0;
	cin >> T;
	if (T <= 0)
		return 0;
	unsigned * a = new unsigned[T];
	for (int i = 0; i < T; i++) {
		cin >> a[i];
		if (a[i] < 0 || a[i] > 1000000000)
			return 0;
	}
	
	for (int i = 0; i < T; i++) {
		cout << logg(a[i]) << endl;
	}
	
	delete [] a;
		
	return 0;
}

int logg(unsigned a)
{
	int ans = 0;
	while (power2(ans) < a)
		++ans;
	return --ans;
}

int power2(unsigned p) {
    int answer = 1;
    /* считаем answer */
	for (unsigned i = 1; i <= p; ++i) {
		answer *= 2;
	}
    return answer;
}
