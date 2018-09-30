#include "bits/stdc++.h"
using namespace std;
//GCD without recursion
int gcd(int a,int b)
{
	int dividend=a;
	int divisor=b;
	while(divisor!=0)
	{
		int remainder=dividend%divisor;
		dividend=divisor;
		divisor=remainder;
	}
	return dividend;
}
int main(int argc, char const *argv[])
{
	cout<<"GCD of 198 & 168 is: "<<gcd(198,168)<<endl;
	return 0;
}