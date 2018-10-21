//Implementation of wavelet tree

#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

//Wavelet tree node structure
struct node
{
	int low,high;
	node *l, *r;
	vector<int> b;

	node(){}

	//constructor for building the wavelet tree
	node(int *s, int *e, int x, int y)
	{
		low=x;
		high=y;
		if(low==high || s>=e)
			return;

		int mid=(low+high)/2;

		auto f=[mid](int x)
		{
			return x<=mid;
		};
		b.reserve(e-s+1);
		b.push_back(0);

		for(auto it=s; it!=e; ++it)
		{
			b.push_back(b.back()+f(*it));
		}

		auto pivot = stable_partition(s, e, f);
		l= new node(s,pivot,low,mid);
		r= new node(pivot,e,mid+1,high);

	}

	//function to find the kth smallest in the range[l,r]
	int kthsmallest(int l, int r, int k)
	{
		if(l>r)
			return 0;
		if(low==high)
			return low;

		int inleft= b[r]-b[l-1];

		int lb=b[l-1];
		int rb=b[r];

		if(k<=inleft)
			return this->l->kthsmallest(lb+1,rb,k);

		return this->r->kthsmallest(l-lb,r-rb,k-inleft);
	}

	//function to count no. in range [l,r] less than or equal to k
	int klessequal(int l, int r, int k)
	{
		if( l>r || k<low)
			return 0;
		if(k>=high)
			return r-l+1;

		int lb=b[l-1];
		int rb=b[r];

		return this->l->klessequal(lb+1,rb,k) + this->r->klessequal(l-lb,r-rb,k);
	}

	//function to count no. in range [l,r] equal to k
	int kequal(int l, int r, int k)
	{
		if(l>r || k<low || k>high)
			return 0;
		if(low==high)
			return r-l+1;
		int lb=b[l-1];
		int rb=b[r];
		int mid=(low+high)/2;

		if(k<=mid)
			return this->l->kequal(lb+1, r, k);
		return this->r->kequal(l-lb, r-rb, k);
	}

	~node()
	{
		delete l;
		delete r;
	}
};


int main()
{
	int a[]={0,1,3,5,4,3,6,4,2}; //0 is the first element as we are using 1 indexing

	int n=sizeof(a)/sizeof(a[0]);
	int high=INT_MIN;

	for (int i = 1; i < n; ++i)
		high=max(high,a[i]);

	node wavelet(a+1,a+n+1,1,high);

	cout<<"The 2nd smallest in the range[1,3] is "<<wavelet.kthsmallest(1,3,2)<<endl;
	cout<<"The 3nd smallest in the range[2,5] is "<<wavelet.kthsmallest(2,5,3)<<endl;
	cout<<"The numbers less than or equal to 4 in range[1,5] is "<<wavelet.klessequal(1,5,4)<<endl;
	cout<<"The numbers equal to 3 in range[1,5] is "<<wavelet.kequal(1,5,3)<<endl;

	return 0;
}

//g++ -std=c++14 wavelet_tree.cpp
//./a.out