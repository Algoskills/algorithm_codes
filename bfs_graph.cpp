#include <bits/stdc++.h>
using namespace std;

//structure for node
struct node
{
    int data;
};
//creating a new node
node *createNode(int val)
{
    node *newNode=new node;
    newNode->data=val;
    return newNode;
}
//adding new edge in graph
void addEdge(vector<node*>g[],int s,int d)
{
    //create a new node and add it to to the adjacency list
    node *temp=createNode(d);
    g[s].push_back(temp);

}
void BFS(vector<node*>g[],int s,int v)
{
    //boolean array to maintain record of visited nodes
    bool visited[v]={0};
    //queue for BFS
    queue<int> q;
    q.push(s);
    visited[s]=1;
    cout<<s<<" ";
    while(!q.empty())
    {
        //get the front element of queue
        int ind=q.front();
        //dequeue the front element
        q.pop();
        //traverse the adjacency list of dequeued node
        for(int i=0;i<g[ind].size();i++)
        {
            int cur=g[ind][i]->data;
            //if current node is not visited push it into queue and mark it visited
            if(!visited[cur])
            {
                cout<<cur<<" ";
                q.push(cur);
                visited[cur]=1;
            }

        }
    }
}
int main()
{
    //No. of vertex,edges and starting source
    int v,e,source;
    cin>>v>>e>>source;
    //adjacency list for graph
    vector<node*>g[v];
    for(int i=0;i<e;i++)
    {
        int s,d;
        cin>>s>>d;
        addEdge(g,s,d);
    }
    BFS(g,source,v);

}




