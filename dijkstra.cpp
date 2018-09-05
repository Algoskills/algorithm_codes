/*

	Dijkstra's shortest path algorithm is used when we need to find the shortest path from a 
	source to a vertex in a graph.
	Here we consider the graph with weighted edges. It may be directed or undirected.

*/

#include <bits/stdc++.h>
using namespace std;

// Dijkstra function which will find distances to all vertices from the source
void dijkstra(vector<list<pair<int,int> > > edges,int V,int src)
{
	// Lets have an array which will store the distances from the source
	int dis[V+1];

	// Initiate all distances to INFINITY
	for(int i=0;i<=V;i++)
	{
		dis[i] = INT_MAX;
	}

	// The distance from the source to itself is 0.
	dis[src] = 0;

	// Here set s will act as the main queue
	set<pair<int,int> > s;

	// We need to check if the vertex is already visited or not to 
	// ensure that we will not move within the loop
	bool visit[V+1];
	memset(visit,false,V+1);

	// Lets push the initial source with the distance from itself as 0 to the main set
	s.insert(make_pair(0,src));

	// Pop the vertices until there are no more left in the set 
	while(!s.empty())
	{
		// Pop the vertex with minimum distance
		pair<int,int> p = *s.begin();
		s.erase(s.begin());

		// Here the vertex x represents current node and wei represents the distance to the 
		// current node from source vertex
		int x = p.second;
		int wei = p.first;

		// Check if the popped vertex is already visited 
		// If the vertex is already visited then we do not consider it
		// as we would have already calculated its distance from the source vertex 
		if(visit[x]) continue;

		// If the vertex is not visited then make it as visited now
		visit[x]=true;

		// Lets have an iterator to iterate over the adjacent vertices of the current node
		list<pair<int,int> >::iterator iter;

		// Iterate over all adjacent vertices
		for(iter=edges[x].begin();iter!=edges[x].end();iter++)
		{
			pair<int,int> pp = *iter;

			// Here e represents the connected node to the current node
			// and w represents the weight of edge between current node to connected node
			int e = pp.first; int w = pp.second;

			// If the weight/distance to the connected node from the source
			// could be minimized through the current node
			if(dis[x] + w < dis[e])
			{
				dis[e] = dis[x] + w;

				// Insert the next vertex with its updated distance 
				s.insert(make_pair(dis[e],e));
			}
		}
	}

	// Print out the distances from the source vertex to all vertices 
	for(int i=1;i<=V;i++)
	{
		if(dis[i]==INT_MAX)
			cout<<"INF ";
		else cout<<dis[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	// Lets create a graph having 9 vertices
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

	// Note that the Graph here we are considering is directed
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

	// We know that Dijkstra's algorithm will be able to find out distances from a specific
	// source. Hence, for example lets have a source s = 1.
	int s = 1;

	cout<<"The distance from source " << s << " is: ";

	dijkstra(edges,V,s);

	return 0;
}