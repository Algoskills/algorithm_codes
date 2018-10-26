//Program to calculate the sum in range[l,r] using sqrt decomposition

#include <iostream>
#include <cmath>

using namespace std;

int block_size;


//function to build blocks
void build(int *a, int *blocks, int n)
{
	for (int i = 0; i < n; ++i)
	{
		blocks[i/block_size]+=a[i];
	}
}

//function for updating the value at certain index
void update(int *a, int *blocks, int index, int value)
{
	int old_value=a[index];
	a[index]=value;
	blocks[index/block_size]+=(value-old_value);
}
//function for query of sum in range[l,r] 
int query(int *a,int *blocks, int l, int r )
{
	int start_block=l/block_size;
	int end_block=r/block_size;
	int sum=0;

	for (int i = l; i < (start_block+1)*block_size; ++i)
	{
		sum+=a[i];
	}
	for (int i = end_block*block_size; i <= r; ++i)
	{
		sum+=a[i];
	}
	for (int i = start_block+1; i < end_block-1; ++i)
	{
		sum+=blocks[i];
	}

	return sum;
}

//driver function
int main()
{
	int a[]={1,4,3,2,4,6,2,1};

	int n=sizeof(a)/sizeof(a[0]);

	block_size= ceil(sqrt(n));

	int blocks[block_size]={0};

	build(a,blocks,n);

	cout<<"The sum(before update) of range [1,5] is "<<query(a,blocks,1,5)<<endl;

	update(a,blocks,3,4);

	cout<<"The sum(after update) of range [1,5] is "<<query(a,blocks,1,5)<<endl;

	return 0;
}