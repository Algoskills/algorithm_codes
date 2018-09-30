    //number of paths to travel from top left to bottom right corner of a grid. You can take one step right or down.
    // if you want to calculate all paths using  left,right,up or down at a time, remove the commented part of the code

    #include<bits/stdc++.h>
    using namespace std;

    const int n=3;
    int c=0;
    bool mat[n][n]={0};
    static int gg=0;
    vector<pair<int,int>> v;
    void paths(int x,int y){
        if(x==n-1&&y==n-1){
            c++;
        }
        else{
            mat[x][y]=1;
            if(x<n-1){
                if(mat[x+1][y]!=1){
                    paths(x+1,y);
                    mat[x+1][y]=0;
                }
            }
            if(y<n-1){
                if(mat[x][y+1]!=1){
                    paths(x,y+1);
                    mat[x][y+1]=0;
                }
            }
            //
            /*
            if(x>0){

                if(mat[x-1][y]!=1){
                    paths(x-1,y);
                    mat[x-1][y]=0;
                }

            }
            if(y>0){
                if(mat[x][y-1]!=1){
                    paths(x,y-1);
                    mat[x][y-1]=0;
                }
            }
            */

        }
    }

    int main(){
       int i,j,k,l;
       paths(0,0);
       cout<<c<<endl;

    }
