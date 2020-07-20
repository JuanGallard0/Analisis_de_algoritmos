#include<iostream>

using namespace std;

int minSearch(int arreglo[], int n)
{
	if (n == 1)
		return arreglo[0];
	else 
		return min(arreglo[n - 1], minSearch(arreglo, n - 1));
}

int main(void)
{
	int arreglo[10] = {42, 63, 31, 70, 53, 92, 21, 23, 34, 88};	
	cout<<minSearch(arreglo, 10)<<endl;
	return 0;
}