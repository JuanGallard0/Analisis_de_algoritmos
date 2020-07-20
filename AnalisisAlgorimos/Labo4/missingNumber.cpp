#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j <= high; ++j)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return i + 1;
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int missingNumber(int arr[], int size)
{
	int x = 2; int temp = 0;
	for (int i = 0; i < size; ++i)
	{
		if ((x == arr[i] or x == arr[i] - 1) and (temp != arr[i] and temp != arr[i] + 1))
		{
			temp = x;
			x += 2;
		}
	}
	if (x == arr[size] or x == arr[size] - 1)
		x += 2;
	return x;
}

int main(void)
{
	int T, N;
	int *A;
	cout<<"T: ";
	cin>>T;
	cout<<endl;
	for (int i = 0; i < T; ++i)
	{
		cout<<"N: ";
		cin>>N;
		A = new int[N];
		cout<<"Array: ";
		for (int j = 0; j < N; ++j)
		{
			cin>>A[j];
		}
		quickSort(A, 0, N);
		cout<<"Missing number: "<<missingNumber(A, N)<<endl<<endl;
	}
	return 0;
}
