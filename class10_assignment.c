// Floyd-Warshall with parent information and negative cycles handled
#include <stdio.h>
#define V 4
#define INF 99999

// prints solution/final matrix 
void printSolution(int dist[][V], int parent[][V]) {
    printf("Floyd-Warshall:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) // check if dist is infinity 
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]); // if not finds and prints dist of path 
        }
        printf("\n");
    }

    // print parent matrix to store parent information 
    printf("\nParent Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (parent[i][j] == -1)
                printf("%7s", "-");
            else
                printf("%7d", parent[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int dist[][V]) {
    int parent[V][V]; // store parent information
    for (int i = 0; i < V; i++) { // initializes parent matrix 
        for (int j = 0; j < V; j++) {
            parent[i][j] = -1; // if no parent = -1
        }
    }

    for (int i = 0; i < V; i++) { // i is vertex which is the source 
        for (int j = 0; j < V; j++) { //j is final vertex
            if (i != j && dist[i][j] != INF) {  
                parent[i][j] = i; // set the parent of j as i
            }
        }
    }

    for (int k = 0; k < V; k++) { // k is current vertex 
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) { // checks for shorter path 
                    dist[i][j] = dist[i][k] + dist[k][j]; // if above has shorter path distance is updated 
                    parent[i][j] = parent[k][j]; // this updates the parent info
                }
            }
        }
    }
    printSolution(dist, parent); // final output printed 
}

int main() {
    int graph[V][V] = { // graph representation 
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    floydWarshall(graph);
    return 0;
}

// Auxilary Space: The parent matrix with parent information consists of a matrix with dimensions [V][V] therefore storing vertices that take up O(n^2)
// The dist matrix also stores pairs of vertices of [v][v] so it also has similar space complexity of O(n^2)
// Therefore overall, auxilary space is of O(n^2)
