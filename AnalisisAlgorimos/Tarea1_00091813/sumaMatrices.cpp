#include<iostream>

using namespace std;

void sumaMatrices(int *A, int *B, int *C, int n)
{
	if (n == 1)
	{
		*C = *A + *B;
		return;
	}
	else
	{
		*(C + n - 1) = *(A + n - 1) + *(B + n - 1);
		return sumaMatrices(A, B, C, n - 1);
	}
}

int main(void)
{
	int A[3][3] = {5, 43, 56, 33, 7, 34, 20, 10, 38};
	int B[3][3] = {35, 7, 24, 47, 3, 36, 0, 40, 42};
	int C[3][3];
	sumaMatrices(*A, *B, *C, 3 * 3);
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout<<"["<<C[i][j]<<"]";
		}
		cout<<endl;
	}
	return 0;
}