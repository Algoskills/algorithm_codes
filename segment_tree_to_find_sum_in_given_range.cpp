
    #include<bits/stdc++.h>
    using namespace std;
    #define rep(i,b) for(i=0;i<b;++i)
    #define repp(i,a,b) for(i=a;i<b;++i)
    #define endl "\n"
    #define pi 3.14159265358979323846
    typedef long long int lli;
    void update(lli *a,lli *tree,lli start,lli last,lli pos,lli val,lli tnode){
        if(start==last){
            tree[tnode]=val;
            a[pos]=val;
        }
        else{
            lli mid=start+(last-start)/2;
            if(start<=pos&&pos<=mid)
                update(a,tree,start,mid,pos,val,2*tnode+1);
            else
                update(a,tree,mid+1,last,pos,val,2*tnode+2);
            tree[tnode]=tree[2*tnode+2]+tree[2*tnode+1];
        }

    }
    lli query(lli *tree,lli tnode,lli start,lli last,lli l,lli r){
        if(r<start||last<l)
            return 0;
        if(l<=start&&last<=r){
            return tree[tnode];
        }
        lli m=start+(last-start)/2;
        lli p,q;
        p=query(tree,2*tnode+1,start,m,l,r);
        q=query(tree,2*tnode+2,m+1,last,l,r);
        return p+q;
    }
    void buildtree(lli *a,lli *tree,lli start,lli last,lli tnode){
        if(start==last){
            tree[tnode]=a[start];
        }
        else{
                lli m=start+(last-start)/2;
            buildtree(a,tree,start,m,2*tnode+1);
            buildtree(a,tree,m+1,last,2*tnode+2);
            tree[tnode]=tree[2*tnode+1]+tree[2*tnode+2];
        }
    }
    int main(){
       //ios_base::sync_with_stdio(false);
       //cin.tie(NULL);
        lli n,t,i,k,q,j,take,ans,ev,od;
        //cin>>t;
        //while(t--){
            cin>>n;//>>q;
            lli a[n];
            lli nn=2*pow(2,ceil(log2(n)))-1;
            lli tree[nn]={0};
            rep(i,n)cin>>a[i];
            buildtree(a,tree,0,n-1,0);
            rep(i,nn)cout<<tree[i]<<endl;
            cout<<"array"<<endl;
            rep(i,n)cout<<a[i]<<" ";
            cout<<endl<<"update: "<<endl;
            cin>>ev>>od;
            update(a,tree,0,n-1,ev-1,od,0);
            rep(i,n)cout<<a[i]<<" ";
            cout<<endl<<"tree"<<endl;
            rep(i,nn)cout<<tree[i]<<endl;
            cout<<"query"<<endl;
            cin>>ev>>od;
            cout<<query(tree,0,0,n-1,ev-1,od-1)<<endl;

        //}
        return 0;
    }
