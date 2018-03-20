#include<iostream>
using namespace std;
//partition returns the appropriate index for pivot
int partition(int a[], int start,int end)
{
  int pivot,i,j,temp;
  pivot = a[end]; 
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

int randomized_partition(int a[], int start,int end)
{
  int size=end-start+1;
  int i=rand() % (size) + start;
  // Uncomment the following line to see the random pivot
  //cout<<"\nrandom pivot is "<<a[i]<< "and i is "<<i<<endl;
  int temp= a[i]; //place random pivot at the end 
  a[i]=a[end];
  a[end]=temp;
  return partition(a,start,end);
}

//array is in the form a[start,...,end]
/*Divides the array into two parts based on the random pivot location obtained from random_partition function and recursively calls them for sorting*/
void randomized_quicksort(int a[],int start,int end)
{
  if( start < end ){
    int pivot_loc= randomized_partition(a,start,end);
    randomized_quicksort(a,start,pivot_loc-1);
    randomized_quicksort(a,pivot_loc+1,end);
  }
}



int main()
{
  int n,i,j;
  cout<<"Enter total number of elements/size: ";
  cin>>n;
  int arr[n];
  cout<<"Enter numbers: ";
  for(i = 0;i< n; i++)// to input the numbers into an array
    cin>>arr[i];
  randomized_quicksort(arr,0,n-1);
  cout<<"Array sorted in increasing order using randomized quicksort: "<< endl;
  for(i = 0;i< n; i++)
    cout<< arr[i]<<" ";
  return 0;
}

