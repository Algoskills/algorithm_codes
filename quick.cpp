#include<iostream>
using namespace std;
int partition(int a[], int start,int end); //forward declaration
void quicksort(int a[],int start,int end);
int main()
{
  int n,i,j;
  cout<<"Enter total number of elements/size: ";
  cin>>n;
  int arr[n];
  cout<<"Enter numbers: ";
  for(i = 0;i< n; i++)// to input the numbers into an array
    cin>>arr[i];
  quicksort(arr,0,n-1);
  cout<<"Array sorted in increasing order: "<< endl;
  for(i = 0;i< n; i++)
    cout<< arr[i]<<" ";
  return 0;
}

//array is in the form a[start,...,end]
/*Divides the array into two parts based on the pivot location obtained from partition function and recursively calls them for sorting*/
void quicksort(int a[],int start,int end)
{
  if( start < end ){
    int pivot_loc= partition(a,start,end);
    quicksort(a,start,pivot_loc-1);
    quicksort(a,pivot_loc+1,end);
  }
}
//partition returns the appropriate index for pivot
int partition(int a[], int start,int end)
{
  int pivot,i,j,temp;
  pivot = a[end]; //usually last element is taken
  i= start-1;
  for(j = start; j<= end-1; j++)
  {
    if(a[j] <= pivot ) {
      i++;
      temp = a[i]; //swap a[i] and a[j]
      a[i] = a[j];
      a[j] = temp;
    }
  }
  temp = a[i+1]; //swap a[i+1] and a[end]/pivot
  a[i+1] = a[end];
  a[end] = temp;
  return i+1; //returning correct/new index of pivot
}