#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (long int i=a;i<n;i++)
#define per(i,a,n) for (long int i=n-1;i>=a;i--)
#define pb push_back
typedef vector<long int> vi;
typedef long long int lli;
const lli mod=1000000007;
lli powmod(lli a,lli b) {lli res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
lli gcd(lli a,lli b) { return b?gcd(b,a%b):a;}

struct node
{
    lli data;
};
node *createNode(lli val)
{
    node *newNode=new node;
    newNode->data=val;

    return newNode;
}

void addEdge(vector<node*>g[],lli s,lli d)
{
    node *temp=createNode(d);
    g[s].pb(temp);
}
void DFS(vector<node*>g[],vector<bool>&visited,lli r,lli v,vi &depth,vector< vector<lli> > &parent)
{
    stack<lli> s;
    //cout<<r<<" ";
    s.push(r);
    while(!s.empty())
    {
        lli cur=s.top();
        s.pop();
        if(!visited[cur])
            {
                //cout<<cur<<" ";
                visited[cur]=1;
            }
        rep(i,0,g[cur].size())
        {
            if(!visited[g[cur][i]->data])
            {
                //visited[g[cur][i]->data]=1;
                parent[g[cur][i]->data][0]=cur;
                depth[g[cur][i]->data]=depth[cur]+1;
                s.push(g[cur][i]->data);
            }
        }
    }
    rep(i,1,log(v)+1)
    {
        rep(j,1,v)
        {
            if(parent[j][i-1]!=-1)
            parent[j][i]=parent[parent[j][i-1]][i-1];
        }
    }

}
lli LCA(vector< vector<lli> > &parent,vi depth,lli u,lli v,lli n)
{
    if(depth[u]<depth[v])
        swap(u,v);

    per(i,0,log(n)+1)
    {
        if(parent[u][i]!=-1&&depth[parent[u][i]]>=depth[v])
            u=parent[u][i];
    }
    if(u==v)
        return u;
    per(i,0,log(n)+1)
    {
        if(parent[u][i]!=parent[v][i])
        {
            u=parent[u][i];
            v=parent[v][i];
        }
    }
    return parent[u][0];
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    lli v,e,r;
    cin>>v>>e>>r;
    //graph *g=createGraph(v);
    vector< vector<lli> > parent;
    parent.resize(v,vector<lli>(log(v)+1,-1));
    vector<bool>visited(v,0);
    vi depth(v,0);
    vector<node*>g[v];
    rep(i,0,e)
    {
        lli s,d;
        cin>>s>>d;
        addEdge(g,s,d);
    }
    DFS(g,visited,r,v,depth,parent);
    lli q;
    cin>>q;
    rep(i,0,q)
    {
        lli a,b;
        cin>>a>>b;
        cout<<LCA(parent,depth,a,b,v)<<endl;
    }

}



