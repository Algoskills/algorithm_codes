#include<iostream>
using namespace std;
int main()
{
	int n,i,j,flag,temp;
	n=6;
	int a[6]={4,66,2,8,9,-85};
	for(i = 0;i< n-1; i++) //for cycles
	{
		flag=0;//flag is given
		for (j = 0; j < (n-1)-i; j++) //for comparison
		{
			if( a[j] > a[j+1]) //use < for decreasing order
			{
				temp= a[j];//temp is used to swap/exchange a[j] and a[j+1]
				a[j]= a[j+1];
				a[j+1]=temp;
				flag=1;//A mark for occurence of swapping
			}
		}
		if(flag==0)//No swapping took place, array is sorted!
		break;
	}
	cout<<"Array sorted in increasing order: "<< endl;
	for(i = 0;i< n; i++)
		cout<< a[i]<<" ";
	return 0;
}
