#include<iostream>

using namespace std;

int potenciacion(int x, int n)
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return x;
	else
		return x * potenciacion(x, n - 1);
}

int main(void)
{
	cout<<potenciacion(2, 4)<<endl;
	return 0;
}