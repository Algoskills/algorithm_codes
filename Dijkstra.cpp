#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (long int i=a;i<n;i++)
#define per(i,a,n) for (long int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
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

void addEdge(vector< pair<node*,lli> >g[],lli s,lli d,lli wt)
{
    node *temp=createNode(d);
    g[s].pb(mp(temp,wt));
    //undirected
    temp=createNode(s);
    g[d].pb(mp(temp,wt));
}
void dijkstra( vector< pair<node*,lli> >g[],lli v,lli src)
{
    vi dist(v,LONG_MAX);
   // cout<<"start"<<endl;
    dist[src]=0;
    set< pair<lli,lli> > s;
    s.insert(mp(dist[src],src));
    while(!s.empty())
    {
        lli u=s.begin()->second;
        s.erase(s.begin());
        rep(i,0,g[u].size())
        {
            pair<node *,lli>p=g[u][i];
            if(dist[p.first->data]>dist[u]+p.second)
            {
                s.erase(mp(dist[p.first->data],p.first->data));
                dist[p.first->data]=dist[u]+p.second;
                s.insert(mp(dist[p.first->data],p.first->data));
            }
        }
    }
    rep(i,0,v)
    {
        if(dist[i]==LONG_MAX)
            cout<<"-1";
        else
            cout<<dist[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    lli v,e,src;
    cin>>v>>e>>src;
    v++;
    //graph *g=createGraph(v);
    vector< pair<node*,lli> >g[v];
    rep(i,0,e)
    {
        lli s,d,wt;
        cin>>s>>d>>wt;
        addEdge(g,s,d,wt);
    }
    dijkstra(g,v,src);

}



