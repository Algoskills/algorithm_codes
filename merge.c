#include<stdio.h>

int i;

void merges(int a[],int p,int r)

{




    int q;

    if(p<r)

    {

        q=(p+r)/2;

        merges(a,p,q);

        merges(a,q+1,r);

        merge(a,p,q,r);

    }

}

void merge(int a[],int p, int q, int r)

{

    int l1, l2, i, b[r];




   for(l1 = p, l2 = q + 1, i = p; l1 <= q && l2 <= r; i++) {

      if(a[l1] <= a[l2])

         b[i] = a[l1++];

      else

         b[i] = a[l2++];

   }




   while(l1 <= q)

      b[i++] = a[l1++];




   while(l2 <= r)

      b[i++] = a[l2++];




   for(i = p; i <= r; i++)

      a[i] = b[i];

}

void main()

{

    int n;




    scanf("%d",&n,printf("Enter Array Size : "));

    int a[n];

    printf("Enter Array :");

    for(i=0;i<n;i++)

        scanf("%d",&a[i]);

    merges(a,0,n-1);

    printf("Sorted Array : ");

    for(i=0;i<n;i++)

        printf("%d ",a[i]);




}
