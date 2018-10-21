//Program for pattern matching using z algorithm

#include <iostream>
#include <string>

using namespace std;

//function to search the pattern
void search(int *z, string s, int n, int p)
{
	for (int i = 0; i < n; ++i)
	{
		if(z[i]==p)
			cout<<"Pattern found at index "<<i-p-1<<endl;
	}
}


//function to construct Z array
void constructzarray(int *z, string s, int n)
{
	int L,R,k;
	L=R=0;
	for (int i = 1; i < n; ++i)
	{
		if(i>R)
		{
			L=R=i;

			while(R<n && s[R-L]==s[R])
				R++;

			z[i]=R-L;
			R--;
		}

		else
		{
			k=i-L;

			if(z[k]<R-i+1)
				z[i]=z[k];

			else
			{
				L=i;
				while(R<n && s[R-L] ==s[R])
					R++;
				z[i]=R-L;
				R--;
			}
		}
	}
}

//driver function
int main()
{
	string str="abacdbabaa";
	string pat="aba";
	string concat=pat+"$"+str;

	int m=pat.length();
	int n=concat.length();
	int z[n]={0};
	constructzarray(z,concat,n);
	search(z,concat,n,m);
}