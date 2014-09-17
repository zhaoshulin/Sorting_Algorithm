#include <iostream>

using namespace std;

inline void swap(int &a, int &b)
{
	int tmp;

	tmp = a;
	a = b;
	b = tmp;
	return;
}

void bubble_sort(int a[], int n)
{
	int i, j;

	for(i = 0; i < n; i ++)
	{
		for(j = i + 1; j < n; j ++)
		{
			if(a[i] > a[j])
				swap(a[i], a[j]);
		}
	}

	return;
}

int main(void)
{
	cout << "swap testing..." << endl;
	int a = 1, b = 2;
	cout << "Before swap, a = " << a << ", b = " << b << endl;
	swap(a, b);
	cout << "After swap, a = " << a << ", b = " << b << endl;

	cout << "bubble_sort_1 testing..." << endl;
	int arr[] = {1, 3, 4, 2, 0, -4, 349, 3};
	int n = 8;
	cout << "Before sorting..." << endl;
	for(a = 0; a < n; a ++)
		cout << " " << arr[a];
	cout << endl;
	cout << "After sorting..." << endl;
	bubble_sort(arr, n);
	for(a = 0; a < n; a ++)
		cout << " " << arr[a];
	cout << endl;
	return 0;
}
