/*

Breadth-first search (BFS) is an algorithm for traversing or searching tree or graph data
structures. It starts at tree root (or some arbitrary node of the graph) and explores
the neighbour nodes first, before moving to the next level neighbours.

BFS is applied while finding the connected components of a graph.

*/


#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int> > edges,int V)
{
	// We will create a boolean array to check if the node has been already visited or not
	// We do this because a graph may contain loops or cycles and we may traverse within it
	bool visited[V];

	// Initialize all vertices to not visited
	for(int i=0;i<=V;i++)
	{
		visited[i]=false;
	}

	// Let us create a queue for BFS
	list<int> queue;

	// Here we are considering the root as source vertex but
	// we can consider any vertex as source
	// Here, we take s as the source equal to 1
	int s = 1;

	//We will visit the source first and will mark it as visited and push it to the queue
	visited[s]=true;
	queue.push_back(s);

	// Lets have an iterator i
	vector<int>::iterator i;

	while(!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		// Get all adjacent vertices of the dequeued vertex
		// If a adjacent is not visited then mark it as visited and enqueue it
		for(i=edges[s].begin();i!=edges[s].end();i++)
		{
			if(!visited[*i])
			{
				visited[*i]=true;
				queue.push_back(*i);
			}
		}
	}
}



int main()
{
	// Lets create a graph having 4 vertices
	// Here V represents number of vertices
	int V = 4;

	// Lets use adjacency list representation of the graph in form of edges
	// Note that here we are using CPP STL
	vector<vector<int> > edges(V+1);
	// Here V+1 is the size of the vector and we have added one to the number of vertices as
	// we are considerng the nodes to be starting from 1 to V

	// Remember that as here we are only considering the traversal within the graph 
	// we are not considering the weights of the edges

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

	cout<<"The Breadth First Traversal is: ";

	BFS(edges,V);

	return 0;
}
