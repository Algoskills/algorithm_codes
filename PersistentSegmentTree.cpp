#include <iostream>

using namespace std;

int a[]={5,9,1,2,3};

// Structure of nodes of tree
struct node
{
	int val;
	node *left,*right;

	node()
	{

	}

	node(node *l,node *r,int v)
	{
		left=l;
		right=r;
		val=v;
	}
};

//array to store versions
node *version[3];


//function to build version 0
void build(node *n,int low, int high)
{
	cout<<"Array: ";
	for (int i = low; i <= high; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	if(low==high)
	{
		n->val=a[low];
		return;
	}

	int mid=(low+high)/2;
	n->left= new node(NULL,NULL,0);
	n->right= new node(NULL,NULL,0);

	build(n->left,low,mid);
	build(n->right,mid+1,high);
	n->val= n->left->val + n->right->val;
}


//function to make other version(to update previous version)
void update(node *prev, node *cur, int low, int high, int idx, int value)
{
	if(idx>high || idx<low || low>high)
		return;

	if(low==high)
	{
		cur->val=value;
		return;
	}
	int mid=(low+high)/2;

	if(idx<=mid)
	{
		cur->right=prev->right;

		cur->left= new node(NULL,NULL,0);
		update(prev->left,cur->left,low,mid,idx,value);
	}
	else
	{
		cur->left=prev->left;
		cur->right= new node(NULL,NULL,0);
		update(prev->right,cur->right,mid+1,high,idx,value);
	}
	cur->val = cur->left->val + cur->right->val;
}

//For query 
int query(node *n, int low, int high, int l, int r)
{
	if(l>high || r<low || low>high)
	{
		return 0;
	}

	if(l<=low && r>=high)
	{
		return n->val;
	}
	int mid=(low+high)/2;
	int x= query(n->left, low, mid, l, r);
	int y= query(n->right, mid+1, high, l, r);

	return x+y;
}
//driver function
int main()
{

	int n= sizeof(a)/sizeof(a[0]);

	node *root= new node(NULL,NULL,0);

	build(root,0,n-1);

	version[0]=root;

	version[1]=new node(NULL,NULL,0);

	update(version[0],version[1],0,n-1,3,1);

	version[2]=new node(NULL,NULL,0);

	update(version[1],version[2],0,n-1,4,8);


	cout << "In version 0 , the sum in range(0,2) is " << query(version[0], 0, n-1, 0, 2) << endl; 

	cout << "In version 1 ,the sum in range(1,3) is "<< query(version[1], 0, n-1, 1, 3) << endl; 
  
    cout << "In version 2 , the sum in range(1,4) is "<< query(version[2], 0, n-1, 1, 4) << endl; 
  
    return 0; 

}