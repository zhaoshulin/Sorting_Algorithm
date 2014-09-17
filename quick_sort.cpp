#include <iostream>
using namespace std;

inline void swap(int &a, int &b)
{
	
	if(a != b)
	{
		a ^= b;
		b ^= a;
		a ^= b;
		cout << "swap over." << endl;
	}
	return;
}

int partition(int arr[], int l, int r)
{
	int dst_pos;
	int i, j;
	int record;

//	swap(arr[0], arr[src_pos]);

	i = l;
	j = r;
	record = arr[l];

	while(j > i)
	{
		while(j > i && arr[j] >= record)
			j --;

		if(j > i)
		{
			arr[i] = arr[j];
			i ++;
		}



		while(i < j && arr[i] < record)
			i ++;

		if(i < j)
		{
			arr[j] = arr[i];
			j --;
		}
	}

	arr[i] = record;
	dst_pos = i;
	return dst_pos;
}

void quick_sort(int arr[], int l, int r)
{
	int dst_pos;
	
	if(l < r)
	{
		dst_pos = partition(arr, l, r);
		quick_sort(arr, l, dst_pos-1);
		quick_sort(arr, dst_pos+1, r);
	}
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
	int arr[] = {1, 32, 4, 2, 56, 23, 6, 3};
	int n = 8;
	cout << "Before sort:" << endl;
	print_array(arr, n);
	cout << "After sort:" << endl;
	quick_sort(arr, 0, n-1);
	print_array(arr, n);
	return 0;
}
