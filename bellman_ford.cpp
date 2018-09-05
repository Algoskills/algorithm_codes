/*

	The Bellman–Ford algorithm is an algorithm that computes shortest paths from
	a single source vertex to all of the other vertices in a weighted digraph.
	It is slower than Dijkstra's algorithm for the same problem, 
	but more versatile, as it is capable of handling graphs in which 
	some of the edge weights are negative numbers.

	Negative edge weights are found in various applications of graphs,
	hence the usefulness of this algorithm. If a graph contains a "negative cycle"
	(i.e. a cycle whose edges sum to a negative value) that is reachable from the source,
	then there is no cheapest path: any path that has a point on the negative cycle
	can be made cheaper by one more walk around the negative cycle.
	In such a case, the Bellman–Ford algorithm can detect negative cycles and report their existence.

*/

#include <bits/stdc++.h>
using namespace std;

// Structure to represent a connected, directed and weigted graph
struct Edge
{
	// src is source vertex, dest is destination vertex and weight is the weight of the edge
	// Here weight can be negative too
	int src, dest, weight;
};

struct Graph
{
	// Here V represents number of Vertices and E represents number of Edges
	int V, E;

	// Graph is represented as an array of edges
	struct Edge* edge;
};

// Dijkstra function which will find distances to all vertices from the source
void Bellman_Ford(struct Graph* graph, int src)
{
	// Lets have the number of vertices and number of edges from the graph
	int V = graph -> V;
	int E = graph -> E;

	// Lets have an array which will store the distances from the source
	int dist[V];

	// Initiate all distances to INFINITY
	memset(dist,INT_MAX,V);

	// The distance from the source to itself is 0.
	dist[src] = 0;

	// Any shortest path from source to vertex can have at most V-1 edges
	// We iterate over all the edges V-1 times in order to find the shortest paths
	// This step will eventually find the shortest paths without considering the negative cycles
	for(int i=1;i<=V-1;i++)
	{
		for(int j=0;j<E;j++)
		{
			// Get the source vertex, destination vertex and weight of the edge
			int u = graph -> edge[j].src;
			int v = graph -> edge[j].dest;
			int weight = graph -> edge[j].weight;

			// Find if the path distance can be reduced 
			// If it can be reduced then update the distance
			if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
			{
				dist[v] = dist[u] + weight;
			}
		}
	}

	// Check for negative-weight cycles.  The above step 
    // guarantees shortest distances if graph doesn't contain 
    // negative weight cycle.  If we get a shorter path, then there
    // is a cycle.
	for(int i=0;i<E;i++)
	{
		int u = graph -> edge[i].src;
		int v = graph -> edge[i].dest;
		int weight = graph -> edge[i].weight;

		if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
		{
			cout << "Path contains negative cycle\n";
		}
	}

	// Print out the distances from the source vertex to all vertices 
	for(int i=0;i<V;i++)
	{
		cout<<dist[i]<<" ";
	}

}

int main()
{
	// Lets create a graph having 5 vertices and 8 edges
	// Here V represents number of vertices and E represents number of Edges
	int V = 5, E = 8;


	// Lets create a graph with a E edges
	struct Graph* graph = new Graph;

	graph -> V = V;
	graph -> E = E;
	graph -> edge = new Edge[E];

	// Now, we will add some edges to the graph

	// add edge 0-1 
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;
 
    // add edge 0-2 
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;
 
    // add edge 1-2 
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;
 
    // add edge 1-3 
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;
 
    // add edge 1-4 
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;
 
    // add edge 3-2 
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;
 
    // add edge 3-1 
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;
 
    // add edge 4-3 
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;

	// We know that Bellman-Ford Algorithm will be able to find out shortest paths from a specific
	// source. Hence, for example lets have a source s = 0.
	int s = 0;

	cout<<"The distance from source " << s << " is: ";

	Bellman_Ford(graph,s);

	return 0;
}