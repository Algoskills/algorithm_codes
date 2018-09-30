#include "bits/stdc++.h"
using namespace std;
int gcd(int a,int b)
{
	if (b==0)
	{
		return a;
	}

	return gcd(b,a%b);
}
int main(int argc, char const *argv[])
{
	cout<<"GCD of 198 & 168 is: "<<gcd(198,168)<<endl;
	return 0;
}