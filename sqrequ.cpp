#include <iostream>
#include <cmath>	//sqrt

using namespace std;

int main()
{
    int a, b, c;

    cin >> a >> b >> c;
	if (a==0)
		return 0;
	double x1 = 0.0, x2 = 0.0;
	double rad = 0.0;
	rad = b*b - 4*a*c;
	if (rad < 0) {
		cout << "No real roots";
		return 0;
	}
	x1 = (-b + sqrt(rad)) / (2 * a);
	x2 = (-b - sqrt(rad)) / (2 * a);
	cout << x1 << " " << x2 << endl;

    return 0;
}
