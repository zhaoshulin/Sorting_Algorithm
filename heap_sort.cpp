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

void min_heap_float_up(int arr[], int n, int target)
{
	int father;

	// input test
	if(target < 0 || target > n-1)
	{
		cerr << "Error: target out of bound!" << endl;
		return;
	}

	if(target == 0)
		return;

	// because: heap is a complete binary tree,
	// so: 
	// father = (target - 1) / 2;
	// lchild = 2 * target + 1;
	// rchild = 2 * target + 2;
	father = (target - 1) / 2;
	while((father >= 0) && (target != 0) && (arr[father] > arr[target]))
	{
		swap(arr[father], arr[target]);
		target = father;
		father = (target - 1) / 2;
	}
	return;
}

void min_heap_sink_down(int arr[], int n, int target)
{
	int smaller_child;

	if(target < 0 || target > n-1)
	{
		cerr << "Error: target out of bound!" << endl;
		return;
	}

	if(target == n-1)
		return;

	smaller_child = 2 * target + 1;

	while(smaller_child < n)
	{
		if(smaller_child + 1 < n && arr[smaller_child] > arr[smaller_child + 1])
			smaller_child ++;

		if(arr[target] <= arr[smaller_child])
			break;
		else
		{
			swap(arr[target], arr[smaller_child]);
			target = smaller_child;
			smaller_child = 2 * target + 1;
		}
	}
	return;
}

void create_min_heap(int arr[], int n)
{
	int nonleaf;

	for(nonleaf = n / 2 - 1; nonleaf >= 0; nonleaf --)
		min_heap_sink_down(arr, n, nonleaf);
	return;
}

void min_heap_sort(int arr[], int n)
{
	int target;

	for(target = n - 1; target >= 1; target --)
	{
		swap(arr[target], arr[0]);
		min_heap_sink_down(arr, target, 0);
	}
	return;
}

inline void print_arr(int arr[], int n)
{
	int i;

	for(i = 0; i < n; i ++)
		cout << " " << arr[i];
	cout << endl;
	return;
}

int main(void)
{
	int i, n;

	cout << "create_min_heap testing..." << endl;
	int arr[] = {9, 12, 17, 30, 50, 20, 60, 65, 4, 49};
	n = 10;
	cout << "Before create, print array:" << endl;
	print_arr(arr, n);
	cout << "After create, print array:" << endl;
	create_min_heap(arr, n);
	print_arr(arr, n);

	cout << "After sort, print array:" << endl;
	min_heap_sort(arr, n);
	print_arr(arr, n);
	return 0;
}
