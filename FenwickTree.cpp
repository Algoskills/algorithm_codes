#include <iostream>
#include <vector>

using namespace std;


//for calculating the sum from 0 to index
int Sum(vector<int> &FTree, int index) 
{ 
    int sum = 0; 

    index = index + 1; 

    while (index>0) 
    { 
        sum += FTree[index]; 
        index -= index & (-index); //To go to next node of tree
    } 

    return sum; 
} 

//To update the value at index
void Update(vector<int> &FTree, int n, int index, int val)
{
	index+=1;
	while(index<=n)
	{
		FTree[index]+=val;

		index += index & (-index);  //To move to its parent
	}
}

//To construct Fenwick tree
vector<int> constructFT(vector<int> a,int n)
{
	vector<int> FTree(n+1,0);
	
	for (int i = 0; i < n; ++i)
	{
		Update(FTree,n,i,a[i]); // Using update to construct it
	}

	return FTree;

}


int main()
{
	vector<int> a={1,4,6,5,3,2,5,9,8};
	int n=a.size();

	vector<int> FTree = constructFT(a,n);


	cout << "Sum of elements(Before Update) of first 4 elements is "<< Sum(FTree, 5)<<endl; 
  
    a[3] += 10; 
    Update(FTree, n, 3, 10);  
  
    cout << "Sum of elements(After Update) of first 4 elements is "<< Sum(FTree, 5)<<endl; 

    return 0;

}



//g++ -std=c++11 FenwickTree.cpp
//./a.out