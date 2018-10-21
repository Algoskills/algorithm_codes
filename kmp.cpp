//Program to implement Knuth Morris Pratt algorthm for pattern matching

#include <iostream>
#include <string>

using namespace std;

//function to find index at which pattern is found
void KMP(string str, string pat, int *pre, int m, int n)
{
	int i=0,j=0;

	while(i<n)
	{
		if(pat[j]==str[i])
		{
			j++;
			i++;
		}

		if(j==m)
		{
			cout<<"Pattern found at index "<<i-j<<endl;
			j=pre[j-1];
		}

		else if(i<n && pat[j]!=str[i])
		{
			if(j!=0)
				j=pre[j-1];
			else
				i=i+1;
		}

	}

}

//function to construct prefix array
int* ConstructPrefix(string pat, int *pre, int m)
{
	int i=1;
	int len=0;

	while(i<m)
	{
		if(pat[i]==pat[len])
		{
			len++;
			pre[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
				len=pre[len-1];
			else
			{
				pre[i]=0;
				i++;
			}
		}
	}

	return pre;
}
//driver function
int main()
{
	string str="abacdbabaa";
	string pat="aba";
	int m=pat.length();
	int n=str.length();
	int prefix[m]={0};
	ConstructPrefix(pat,prefix,m);
	KMP(str,pat,prefix,m,n);

	return 0;
}