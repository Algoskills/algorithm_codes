#include<iostream>
using namespace std;
void bubble(int a[], int n); //forward declaration
int main()
{
	int n,i,j;
	cout<<"Enter total number of elements/size: ";
	cin>>n;
	int arr[n];
	cout<<"Enter numbers: ";
	for(i = 0;i< n; i++)// to input the numbers into an array
		cin>>arr[i];
	bubble(arr,n);
	cout<<"Array sorted in increasing order: "<< endl;
	for(i = 0;i< n; i++)
		cout<< arr[i]<<" ";
	return 0;
}

void bubble(int a[], int n) //Notice something special? read explanation below!
{
	int i,j,temp;
	for(i = 0;i< n-1; i++) //for cycles
		for (j = 0; j < (n-1)-i; j++) //for comparison
		{
			if( a[j] > a[j+1]) //use < for decreasing order
			{
				temp= a[j];//temp is used to swap/exchange a[j] and a[j+1]
				a[j]= a[j+1];
				a[j+1]=temp;
			}
		}
}
