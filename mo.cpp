//Program to find no. of distinct elements in the range[l,r] efficiently using mo's algorithm

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int block_size;
int MAX=1000000;

//structure for one query
//index is to store actual index of query
struct query
{
	int l, r , index, result;
};


//to sort queries according to mo's algorithm
bool mosort(query x, query y)
{
	if(x.l/block_size != y.l/block_size)
		return x.l/block_size < y.l/block_size;
	return x.r < y.r;
}


//for actual sorting if queries
bool actualsort(query x, query y)
{
	return x.index < y.index;
}


//find, store and print result of queries
void distinct(int *a, int n, query q[], int m)
{
	block_size = int(sqrt(n));

	sort(q,q+m,mosort);
	
	int cl=0,cr=0,count=0;

	int freq[MAX]={0};

	for (int i = 0; i < m; ++i)
	{
		int l=q[i].l, r=q[i].r;
		while(cl<l)
		{
			freq[a[cl]]--;
			if(freq[a[cl]]==0)
				count--;
			cl++;
		}
		while(cl>l)
		{
			freq[a[cl-1]]++;
			if(freq[a[cl--]]==1)
				count++;
			cl--;
		}

		while(cr<=r)
		{
			freq[a[cr]]++;

			if(freq[a[cr]]==1)
				count++;

			cr++;
		}

		while(cr>=r+1)
		{
			freq[a[cr-1]]--;

			if(freq[a[cr-1]]==0)
				count--;
			cr--;
		}

		q[i].result=count;

	}

	sort(q,q+m,actualsort);

	for (int i = 0; i < m; ++i)
	{
		cout<<"The no. of distinct elements between "<<q[i].l<<" and "<<q[i].r-1<<" is "<<q[i].result<<endl;
	}
}

//driver function
int main()
{
	int a[]={1,2,3,3,4,6,5,4,4,7};

	query q[]={{0,9,0,0},{0,5,1,0}};

	int n = sizeof(a)/sizeof(a[0]);

	int m = sizeof(q)/sizeof(q[0]);

	distinct(a,n,q,m);

	return 0;

}