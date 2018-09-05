/*

	the Floyd–Warshall algorithm is an algorithm for finding shortest paths in a weighted graph 
	with positive or negative edge weights (but with no negative cycles).A single execution of 
	the algorithm will find the lengths (summed weights) of the shortest paths between all pairs 
	of vertices.

*/

#include <bits/stdc++.h>
using namespace std;
#define INF 99999

// Dijkstra function which will find distances to all vertices from the source
void Floyd_Warshall(vector<list<pair<int,int> > > edges,int V)
{
	// Lets have an array which will store the distances from the source
	int dist[V+1][V+1];

	// The distances initially will be infinity besides 
	//the distances between the vertex to itself will be zero
	for(int i=1;i<=V;i++)
	{
		for(int j=1;j<=V;j++)
		{
			if(i==j)
				dist[i][j] = 0;
			else dist[i][j]=INF;
		}
	}

	// Lets have an iterator to iterate over the lists
	list<pair<int,int> >::iterator iter;

	// Copy the known distances between the vertices to dist matrix
	for(int i=1;i<=V;i++)
	{
		for(iter=edges[i].begin();iter!=edges[i].end();iter++)
		{
			pair<int,int> p = *iter;
			
			int v = p.first;
			int weight = p.second;

			// Update the known distance
			dist[i][v] = weight;
		}
	}

	// Calculate the shortest path considering k as connecting vertex between i and j
	for(int k=1;k<=V;k++)
	{
		for(int i=1;i<=V;i++)
		{
			for(int j=1;j<=V;j++)
			{
				// Check is we consider the traversal through k from i to j
				// can the distance be minimized
				if(dist[i][k] + dist[k][j] < dist[i][j])
				{
					// if the distance can be minimized then update the distance
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	// Print out the distances from the source vertex to all vertices 
	for(int i=1;i<=V;i++)
	{
		for(int j=1;j<=V;j++)
		{
			// Here INF means there are no paths from i to j
			if(dist[i][j] == INF)
				cout<<"INF\t";
			else cout<<dist[i][j]<<"\t";
		}
		cout<<endl;
	}

}

int main()
{
	// Lets create a graph having 4 vertices
	// Here V represents number of vertices
	int V = 9;

	// Lets use adjacency list representation of the graph
	// Note that here we are using CPP STL
	vector<list<pair<int,int> > > edges(V+1);
	// Here V+1 is the size of the vector and we have added one to the number of vertices as
	// we are considerng the nodes to be starting from 1 to V 

	// Now, we will add some edges to the graph
	// Say, we want to add an edge between node 1 and node 2 with weight 4:
	edges[1].push_back(make_pair(2,4));

	// Note here that the Graph here we are considering is directed
	// If we want to have an undirected graph then we will need to push the vextex to the 
	// connecting vertex too. 

	// add an edge between node 1 and node 8 with weight 8:
	edges[1].push_back(make_pair(8,8));

	// add an edge between node 2 and node 3 with weight 8:
	edges[2].push_back(make_pair(3,8));

	// add an edge between node 2 and node 8 with weight 11:
	edges[2].push_back(make_pair(8,11));

	// add an edge between node 3 and node 4 with weight 7:
	edges[3].push_back(make_pair(4,7));

	// add an edge between node 3 and node 9 with weight 2:
	edges[3].push_back(make_pair(9,2));

	// add an edge between node 3 and node 6 with weight 4:
	edges[3].push_back(make_pair(6,4));

	// add an edge between node 4 and node 5 with weight 9:
	edges[4].push_back(make_pair(5,9));

	// add an edge between node 4 and node 6 with weight 14:
	edges[4].push_back(make_pair(6,14));

	// add an edge between node 5 and node 6 with weight 10:
	edges[5].push_back(make_pair(6,10));

	// add an edge between node 6 and node 7 with weight 2:
	edges[6].push_back(make_pair(7,2));

	// add an edge between node 7 and node 8 with weight 1:
	edges[7].push_back(make_pair(8,1));

	// add an edge between node 7 and node 9 with weight 6:
	edges[7].push_back(make_pair(9,6));

	// add an edge between node 8 and node 9 with weight 7:
	edges[8].push_back(make_pair(9,7));

	cout<<"The distance matrix contsaining the shortest paths between all pair of vertices will be:\n\n";

	Floyd_Warshall(edges,V);

	return 0;
}