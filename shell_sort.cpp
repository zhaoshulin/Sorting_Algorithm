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

void shell_sort(int arr[], int n)
{
	int i, j, step;

	for(step = n/2; step >=1; step /= 2) // Outer Shell_sorting
	{
		// Inner Insert_sorting
		for(i = step; i < n; i ++)
		{
			for(j = i - step; j >= 0 && arr[j+step] < arr[j]; j -= step)
				swap(arr[j], arr[j+step]);
		}
	}
	return;
}

int main(void)
{
	int i;
	cout << "shell_sort testing..." << endl;
	int arr[] = {1, 3, 4, 2, 4, 5, 2, 5, 2};
	int n = 9;

	cout << "Before sort: " << endl;
	for(i = 0; i < n; i ++)
		cout << " " << arr[i];
	cout << endl;
	shell_sort(arr, n);
	cout << "After sort: " << endl;
	for(i = 0; i < n; i ++)
		cout << " " << arr[i];
	cout << endl;
		
	return 0;
}
