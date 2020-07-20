#include<iostream>

using namespace std;

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		printArray(arr, 10);
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		printArray(arr, 10);
		heapify(arr, i, 0);
	}
}

int main(void)
{
	int arr[] = {88, 85, 83, 72, 73, 42, 57, 6, 48, 60};
	printArray(arr, 10);
	heapSort(arr, 10);
	return 0;
}