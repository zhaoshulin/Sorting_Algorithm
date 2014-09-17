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

// merge two sorted array: arr[first, .., middle] and arr[middle+1, .., end]
void merge_sorted_array(int arr[], int first, int middle, int end, int tmp[])
{
	int i, j, k;

	i = first;
	j = middle + 1;
	k = 0;
	
	while(i <= middle && j <= end)
	{
		tmp[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
	}

	while(i <= middle)
		tmp[k++] = arr[i++];
	while(j <= end)
		tmp[k++] = arr[j++];

	for(i = 0; i < k; i ++)
		arr[first+i] = tmp[i];
	return;
}

void merge_sort(int arr[], int first, int end, int tmp[])
{
	if(first < end)
	{
		int middle;
		middle = (first + end) / 2;

		merge_sort(arr, first, middle, tmp);
		merge_sort(arr, middle+1, end, tmp);
		merge_sorted_array(arr, first, middle, end, tmp);
	}
	return;
}

bool main_merge_sort(int arr[], int n)
{
	int* tmp_p = new int[n];
	if(!tmp_p)
	{
		cerr << "Error: new failed!" << endl;
		return false;
	}

	merge_sort(arr, 0, n-1, tmp_p);
	delete[] tmp_p;
	return true;
}

inline void print_array(int arr[], int n)
{
	int i;

	for(i = 0; i < n; i ++)
		cout << " " << arr[i];
	cout << endl;
	return;
}

int main(void)
{
	cout << "merge_sort testing..." << endl;
	int arr[] = {1, 2, 3, 1, 3, 6, 7, 5, 3, 5, 7, 9, 70, 22};
	int n = 14;
	cout << "Before sort:" << endl;
	print_array(arr, n);

	main_merge_sort(arr, n);
	cout << "After sort:" << endl;
	print_array(arr, n);
	return 0;
}
