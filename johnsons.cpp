/*

	We know that if we have to find the shortest path betwwen all pairs in a graph then
	we can apply Floyd Warshall's Algorithm. But the time complexity of Floyd Warshall's 
	Algorithm is O(n^3). Instead if we applied Dijkstra's Algorithm for all verices as source
	the time complexity is reduced to O(V^2 log V + VE).

	Hence it works better than Floyd Warshall. But the problem with Dijkstra's algorithm 
	is that it doesen't work for negative edges. Hence Johnson's Algorithm suggests that 
	we can reduce the negative edges to non-negative weights and then apply Dijkstra's 
	algorithm to all vertices. 

	The preocess for converting the negative weights into positive is to add a weight to every 
	weight of an edge. We cannot certainly add the minimum weight as there are different 
	connections between vertices and we have to be sure that the smallest weight connected to 
	a certain vertex is still smallest after adding.

	We calculate an array, say h[] which contain the constants for every vertex. We then add 
	h[v]-h[u] for edge between u and v. For negative cycles we use Bellman-Ford Algorithm.
	The construction of h[] array is as follows:
	1. Connect a new vertex s to all existing vertices. 
	2. Calculate shortest paths to every vertex considering s as source.
	3. The shortest path array will be h[].
	

*/

#include <bits/stdc++.h>
using namespace std;
#define INF 99999

// Lets create a graph having 9 vertices and 13 edges
// Here V represents number of vertices and E represents number of Edges
int V = 9, E = 13;

// Lets use adjacency list representation of the graph
// Note that here we are using CPP STL
vector<list<pair<int,int> > > edges(V+2);
// Here V+1 is the size of the vector and we have added one to the number of vertices as
// we are considerng the nodes to be starting from 1 to V 

int dist[INF]={0};

int dist_mat[1001][1001];

bool visited[INF];

// Bellman Ford Algorithm to find if there are any megative cycles within the graph
// after inserting the new vertex
int Bellman_Ford(int s)
{
	// Initialize all distances to infinity and mark all vertices as not visited
	for(int i=1;i<=V;i++)
	{
		dist[i] = INF;
		visited[i] = false;
	}

	// Distance to source from source is zero
	dist[s] = 0;

	// x represents ending vertex of an edge
	// w represents weight of the edge 
	int x,w;

	// Iterator to iterate over the adjacent edges
	list<pair<int,int> >::iterator iter;

	// Find if the distance from the starting vertex to ending vertex can be minimized
	// if we are traversing through the current vertex
	for(int k=1;k<=V;k++)
	{
		for(int j=1;j<=V+1;j++)
		{
			for(iter=edges[j].begin();iter!=edges[j].end();iter++)
			{
				pair<int,int> pp = *iter;

				x = pp.first;
				w = pp.second;

				// If the distance can be minimized then update the distance
				if(dist[j] + w < dist[x] && dist[j] != INF)
				{
					dist[x] = w + dist[j];
				} 
			}
		}
	}

	// Returning value
	// Will return 1 if the graph contains a negative cycle else 0
	int temp=0;

	// Check for negative cycles
	for(int j=1;j<=V+1;j++)
	{
		for(iter=edges[j].begin();iter!=edges[j].end();iter++)
		{
			pair<int,int> pp = *iter;

			x = pp.first;
			w = pp.second;

			if(dist[j] + w < dist[x] && dist[j] != INF)
			{
				temp = 1;
			} 
		}
	}
	return temp;
}

// Dijkstra function which will find distances to all vertices from the source
void Dijkstra(int src)
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
		dist_mat[src][i] = dis[i];
	}
}

void Johnsons_Algorithm()
{
	// Connect the new vertex to all vertices with edge weight 0
	for(int i=1;i<=V;i++)
	{
		edges[V+1].push_back(make_pair(i,0));
	}

	// Bellman_FOrd will return 1 if the graph contains a negative cycle
	if(Bellman_Ford(V+1))
	{
		cout<<"Negative Cycle Present!\n";
	}
	else
	{
		// x represents ending vertex of an edge
		// w represents weight of the edge
		int x, w;

		list<pair<int,int> >::iterator iter;	

		// Update the distances so that the new distances would not contain any negative weights
		for(int j=1;j<=V+1;j++)
		{
			for(iter=edges[j].begin();iter!=edges[j].end();iter++)
			{
				pair<int,int> p = *iter;

				x = p.first;
				w = p.second;

				p.second = w + (dist[j] - dist[x]);

				*iter = p; /** Haven't tried if this work! Please someone confirm! **/
			}
		}

		/*for(int j=1;j<=V+1;j++)
		{
			for(iter=edges[j].begin();iter!=edges[j].end();iter++)
			{
				pair<int,int> p = *iter;

				x = p.first;
				w = p.second;
			}
		}*/

		// Clear out the entry of new vertex inserted
		edges[V+1].clear();

		// Initialize all distances to zero
		for(int i=0;i<1001;i++)
		{
			for(int j=0;j<1001;j++)
			{
				dist_mat[i][j] = 0;
			}
		}

		// Apply Dijkstra to every vertex
		for(int i=1;i<=V;i++)
		{
			Dijkstra(i);
		}

		// Print shortest paths for all vertices

		cout<<"Shortest distances between all vertices:\n\n";
		for(int i=1;i<=V;i++)
		{
			for(int j=1;j<=V;j++)
			{
				cout<<dist_mat[i][j]<<"\t";
			}
			cout<<endl;
		}
	}
}

int main()
{
	// As we have used adjacency list representation of the graph, we will add edges to the graph.
	// Say, we want to add an edge between node 1 and node 2 with weight 4:
	edges[1].push_back(make_pair(2,4));
	edges[2].push_back(make_pair(1,4));

	// add an edge between node 1 and node 8 with weight 8:
	// add an edge between node 1 and node 8 with weight 8:
	edges[1].push_back(make_pair(8,8));
	edges[8].push_back(make_pair(1,8));

	// add an edge between node 2 and node 3 with weight 8:
	edges[2].push_back(make_pair(3,8));
	edges[3].push_back(make_pair(2,8));

	// add an edge between node 2 and node 8 with weight 11:
	edges[2].push_back(make_pair(8,11));
	edges[8].push_back(make_pair(2,11));

	// add an edge between node 3 and node 4 with weight 7:
	edges[3].push_back(make_pair(4,7));
	edges[4].push_back(make_pair(3,7));

	// add an edge between node 3 and node 9 with weight 2:
	edges[3].push_back(make_pair(9,2));
	edges[9].push_back(make_pair(3,2));

	// add an edge between node 3 and node 6 with weight 4:
	edges[3].push_back(make_pair(6,4));
	edges[6].push_back(make_pair(3,4));

	// add an edge between node 4 and node 5 with weight 9:
	edges[4].push_back(make_pair(5,9));
	edges[5].push_back(make_pair(4,9));

	// add an edge between node 4 and node 6 with weight 14:
	edges[4].push_back(make_pair(6,14));
	edges[6].push_back(make_pair(4,14));

	// add an edge between node 5 and node 6 with weight 10:
	edges[5].push_back(make_pair(6,10));
	edges[6].push_back(make_pair(5,10));

	// add an edge between node 6 and node 7 with weight 2:
	edges[6].push_back(make_pair(7,2));
	edges[7].push_back(make_pair(6,2));

	// add an edge between node 7 and node 8 with weight 1:
	edges[7].push_back(make_pair(8,1));
	edges[8].push_back(make_pair(7,1));

	// add an edge between node 7 and node 9 with weight 6:
	edges[7].push_back(make_pair(9,6));
	edges[9].push_back(make_pair(7,6));

	// add an edge between node 8 and node 9 with weight 7:
	edges[8].push_back(make_pair(9,7));
	edges[9].push_back(make_pair(8,7));

	Johnsons_Algorithm();

	return 0;
}