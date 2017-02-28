#include <iostream>
using namespace std;

//create a 2d array
int ** creat_array2d(size_t a, size_t b)
{
	int ** m = new int * [a];
	m[0] = new int[a*b];
	for (size_t i = 1; i != a; ++i) {
		m[i] = m[i-1] + b;
	}
	return m;
}
//delete it
void freee_array2d(int ** m, size_t a, size_t b)
{
	delete [] m[0];
	delete [] m;
}

//transposes a 2d matrix

int ** transpose(const int * const * m, unsigned rows, unsigned cols) 
//declare m as pointer to const pointer to const int
{
    int ** new_m = creat_array2d(cols, rows);
	for (unsigned r = 0; r != cols; ++r) {
		for (unsigned c = 0; c != rows; ++c) {
			new_m[r][c] = m[c][r];
		}
	}
	return new_m;
}

void init_array2d(int ** m, unsigned rows, unsigned cols)
{
	for (int r = 0; r != rows; ++r) {
		for (int c = 0; c != cols; ++c) {
			m[r][c] = c+1-r;
		}
	}
}

void out_arr(const int * const * m, unsigned rows, unsigned cols)
{
	for (size_t ir = 0; ir != rows; ++ir) {
		for (size_t ic = 0; ic != cols; ++ic) {
			cout << m[ir][ic] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	size_t r = 2, c = 3;
	int ** arr = creat_array2d(r, c);
	init_array2d(arr, r, c);
	out_arr(arr, r, c);
	int ** arr_t = transpose(arr, r, c);
	out_arr(arr_t, c, r);
	
	freee_array2d(arr_t, c, r);
	freee_array2d(arr, r, c);
	
	return 0;
}
