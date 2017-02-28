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

//finds th minimal value in a 2d array, returns the number of the row where it was found
unsigned find_row_with_min(const int * const * m, unsigned rows, unsigned cols)
{
	int min = m[0][0];
	unsigned row = 0;
	for (int r = 0; r != rows; ++r) {
		for (int c = 0; c != cols; ++c) {
			if (m[r][c] < min) {
				min = m[r][c];
				row = r;
			}	
		}
	}
	return row;
}

//swaps two lines - a line with a min val and the first one - using the returned number of th row
void swap_min(int *m[], unsigned rows, unsigned cols)
{
	unsigned row = find_row_with_min(m, rows, cols);
	//if the line with min isn't the line 0
	if (row) {
		int *m_temp; 		// temporary pointer for storing the 0-th line
		m_temp = m[0];
		m[0] = m[row];
		m[row] = m_temp;
	}
}

int main()
{
	size_t r = 3, c = 3;
	int ** arr = creat_array2d(r, c);
	init_array2d(arr, r, c);
	out_arr(arr, r, c);
	swap_min(arr, r, c);
	out_arr(arr, r, c);
	freee_array2d(arr, r, c);
	
	return 0;
}
