#include <iostream>
using namespace std;

void rotate(int a[], unsigned size, int shift)
{
	if (shift != size || shift%size != 0) {
		
		if (shift > size) {
			shift = shift%size;
		}
			
		for (int c = 0; c < shift; c++) {
			int temp = 0;
			int i = 0, j = size-1;
			for (; i < j; ++i) {
				for (; j > i; --j){
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
	}
}

int main()
{
	unsigned sz = 5;
    int * array = new int[sz];
	int sh = 0;
	cout << "Shift: ";
	cin >> sh;
	
	for (int i = 0; i < sz; i++)
	{
		array[i] = i+1;
	}
	
	rotate(array, sz, sh);
	
	for (int i = 0; i < sz; i++)
	{
		cout << array[i] << " ";
	}
	
	delete [] array;	
	return 0;
}
