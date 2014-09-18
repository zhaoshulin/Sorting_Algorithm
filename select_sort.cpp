#include <iostream>
using namespace std;

inline void swap(int &a, int &b)
{
	if(a != b)
	{
		a ^= b;
		b ^= a;
		a ^= b;
	}
	return;
}

void select_sort(int arr[], int n)
{
	int i, j, min_index;
	
	if(n <= 1)
		return;

	for(i = 0; i < n; i ++)
	{
		min_index = i;
		for(j = i + 1; j < n; j ++)
		{
			if(arr[min_index] > arr[j])
				min_index = j;	
		}// now have found min_index

		swap(arr[i], arr[min_index]);
	}

	return;
}

int main(void)
{
	int i;

	cout << "select_sort testing..." << endl;
	int arr[] = {0, 3, 2, 4, 1, 4, 5, 9, 7, 2};
	int n = 10;
	cout << "Before sort:" << endl;
	for(i = 0; i < n; i ++)
		cout << " " << arr[i];
	cout << endl;

	select_sort(arr, n);
	cout << "After sort:" << endl;
	for(i = 0; i < n; i ++)
		cout << " " << arr[i];
	cout << endl;
	return 0;
}
