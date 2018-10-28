#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e5 + 9;
const long long INF = 1e6 + 9;
typedef long long lli;
typedef unsigned long long uli;
vector<int>g[MAX];
queue<int>que;
int color[MAX];
bool isBipartite;

bool bipartite(int s){
	que.push(s);
	color[s] = 0;
	isBipartite = true;
	while(!que.empty() && isBipartite)
	{
		int x = que.front();
		que.pop();
		cout<<x<<endl;
		for (int i = 0; i < g[x].size(); ++i)
		{
			int y = g[x][i];
			if(color[y] == INF)
			{
				color[y] = 1 - color[x];
				que.push(y);
			}
			
			if(color[y] == color[x])
			{
				isBipartite = false;
			}
		}
	}
	if(isBipartite)return true;
	return false;
}

int main()
{
	int n,m,u,v;
	cin>>n>>m;
	for(int i=0;i<=n;i++)
	{
		color[i] = INF;
	}

	while(m--){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}		
	bipartite(1);

	for(int i=1;i<=n;i++)
		cout<<color[i]<<" ";
	
	cout<<endl; 
	if(isBipartite)cout<<"is bipartite graph"<<endl;
	else cout<<"not a bipartite graph"<<endl;
	return 0;
}