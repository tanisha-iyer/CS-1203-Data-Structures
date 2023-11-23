for (int v = 0; v < V; v++)
    dist[v] = min, sptSet[v] = false;
    
dist[src] = 0;

int storePath[V];

for (count = 0; count < V-1; count++) {
    int u = minDistance(dist, sptSet);
    sptSet[u] = true;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
            && dist[u] + graph[u][v] < dist[v]) {
            dist[v] = dist[u] + graph[u][v];
            storePath[v] = u; 
        }
    }
}

// This will work for directed graphs as well since Dijkstra's algorithm will work as long as all weights are positive/non-negative. 
// The algorithm only looks at edges that are present in the graph. In a directed graph, an edge from u to v is not the same as an edge from v to u, which graph[u][v] condition takes care of.

// To improve the time complexity, we can use a different data structure. For example a binary search tree which is organized 
// according to the value of the nodes can make Dijkstra’s shortest path be performed more efficiently. 
// The time complexity then becomes O(log(n)) where n is the number of vertices and edges in the graph

// src initialized to a priority queue with a distance of 0.
// The main loop continues under condition that it is not empty
// In each iteration, the vertex u with the smallest distance is removed from queue and added to a new array (storePath[])

