//Program to find the exponent efficiently

#include <iostream>

using namespace std;

//fast exponentiation function
int power(int n, int k)
{
	if(k==0)
		return 1;
	else if(k==1)
		return n;
	else
	{
		int x=power(n,k/2);
		
		if(n%2==0)
		{
			return x*x;
		}
		else
		{
			return x*n*x;
		}
	}
}

//driver function
int main()
{
	int n=2,k=20;

	cout<<power(n,k)<<endl;

	return 0;
}
