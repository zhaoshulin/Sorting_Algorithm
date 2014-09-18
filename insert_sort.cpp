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

void insert_sort(int arr[], int n)
{
	int i, j;

	for(i = 1; i < n; i ++)
	{
		for(j = i - 1; j >= 0 && arr[j+1] < arr[j]; j --)
			swap(arr[j], arr[j+1]);
	}
	return;
}

int main(void)
{
	int i;

	cout << "insert_sort testing..." << endl;
	int arr[] = {0, -3, 2, -4, 3, 45, 84};
	int n = 7;
	cout << "Before sorting: " << endl;
	for(i = 0; i < n; i ++)
		cout << " " << arr[i];
	cout << endl;
	insert_sort(arr, n);
	cout << "After sorting:" << endl;
	for(i = 0; i < n; i ++)
		cout << " " << arr[i];
	cout << endl;
	return 0;
}
