#include <iostream>
using namespace std;

int main()
{
    // put your code here
    int T = 0;
	cin >> T;
	if (T <= 0)
		return 0;
	int * sum = new int[T];
	for (int i = 0; i < T; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		sum[i] = (a+b);
	}
	for (int i = 0; i < T; i++)
	{
		cout << sum[i] << endl;
	}
	delete [] sum;
    return 0;
}
