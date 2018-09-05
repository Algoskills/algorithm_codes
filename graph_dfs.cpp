/*

Depth-first search (DFS) is an algorithm for traversing or searching tree or graph data structures
One starts at the root (selecting some arbitrary node as the root in the case of a graph)
and explores as far as possible along each branch before backtracking.

*/


#include <bits/stdc++.h>
using namespace std;

// DFS Helper function to recursively go through all adjacents of a vertex
void DFS_Help(vector<vector<int> > edges,bool visited[],int s)
{
	// Mark the current node as visited and print it out
	visited[s]=true;
	cout<<s<<" ";

	// Lets have an iterator i
	vector<int>::iterator i;

	// Recur for all the vertices adjacent to the source vertex
	for(i=edges[s].begin();i!=edges[s].end();i++)
	{
		if(!visited[*i])
		{
			DFS_Help(edges,visited,*i);
		}
	}
}

void DFS(vector<vector<int> > edges,int V)
{
	// We will create a boolean array to check if the node has been already visited or not
	// We do this because a graph may contain loops or cycles and we may traverse within it
	bool visited[V];

	// Initialize all vertices to not visited
	for(int i=0;i<=V;i++)
	{
		visited[i]=false;
	}

	// Here we are considering the source as 1
	// we can consider any vertex as source
	// Hence, s is the source which is equal to 1
	int s = 1;

	// For finding out DFS Traversal we will need a recursive helper function
	// which will go through every adjacent vertex of a vertex as a source
	// Initially our source is s = 1
	DFS_Help(edges,visited,s);
}



int main()
{
	// Lets create a graph having 4 vertices
	// Here V represents number of vertices
	int V = 4;

	// Lets use adjacency list representation of the graph
	// Note that here we are using CPP STL
	vector<vector<int> > edges(V+1);
	// Here V+1 is the size of the vector and we have added one to the number of vertices as
	// we are considerng the nodes to be starting from 1 to V 

	// Remember that as here we are only considering the traversal within the graph 
	// so we are not considering the weights of the edges

	// Now, we will add some edges to the graph
	// Say, we want to add an edge between node 1 and node 2:
	edges[1].push_back(2);

	// add an edge between node 1 and node 3:
	edges[1].push_back(3);

	// add an edge between node 2 and node 3:
	edges[2].push_back(3);

	// add an edge between node 3 and node 1:
	edges[3].push_back(1);

	// add an edge between node 3 and node 4:
	edges[3].push_back(4);

	// add an edge between node 4 and node 4:
	edges[4].push_back(4);

	cout<<"The Depth First Traversal is: ";

	DFS(edges,V);

	return 0;
}
