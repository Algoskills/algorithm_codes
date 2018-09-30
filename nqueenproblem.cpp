    //n queen problem

    #include<bits/stdc++.h>
    using namespace std;
    const int n=4;
    int col[n]={0};
    int diag1[2*n-1]={0};
    int diag2[2*n-1]={0};
    vector<pair<int,int>> v;
    void nqueen(int y){
        if(v.size()==n){
            for(int i=0;i<v.size();i++)cout<<v[i].first<<" "<<v[i].second<<endl;
            cout<<endl;
            return;
        }
        else{
            for(int x=0;x<n;x++){
                if(col[x]||diag1[x+y]||diag2[x-y+n-1])
                    continue;
                col[x]=diag1[x+y]=diag2[x-y+n-1]=1;
                v.push_back(make_pair(x,y));
                nqueen(y+1);
                col[x]=diag1[x+y]=diag2[x-y+n-1]=0;
                v.pop_back();
            }
        }
    }

    int main(){
       //ios_base::sync_with_stdio(false);
       //cin.tie(NULL);
       int i,j,k,l;
       nqueen(0);

    }
