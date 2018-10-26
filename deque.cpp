//Program to implement deque for finding the maximum of all suaarays of size k
#include <iostream>
#include <deque>

using namespace std;

int main()
{
	int a[]={1,43,23,11,46,22,81,22};

	int n=sizeof(a)/sizeof(a[0]);
	int k=3;

	deque<int> d;

	int i;
	for (i = 0; i < k; ++i)
	{
		while(!d.empty() && a[i]>=a[d.back()])
			d.pop_back();
		d.push_back(i);
	}
	for (; i < n; ++i)
	{
		cout<<a[d.front()]<<" ";

		while(!d.empty() && d.front()<=i-k)
			d.pop_front();

		while(!d.empty() && a[i]>=a[d.back()])
			d.pop_back();
		d.push_back(i);

	}
	cout<<a[d.front()]<<endl;

	return 0;
}