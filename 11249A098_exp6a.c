#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define V 6
int findMin(int dist[], bool visited[]) {
    int min = INT_MAX, index = -1;
    int i;
    for (i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}
void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool visited[V];
    int i, v, u;
    // Initialize distances and visited array
    for (i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[src] = 0;
    // Find shortest path
    for (i = 0; i < V - 1; i++) {
        u = findMin(dist, visited);
        visited[u] = true;
        for (v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    // Print result
    printf("Vertex\tDistance\n");
    for (i = 0; i < V; i++) {
        printf("%c\t%d\n", i + 'A', dist[i]);
    }
}
int main() {
    int graph[V][V] = {
        {0,1,2,0,0,0},
        {1,0,0,5,1,0},
        {2,0,0,2,3,0},
        {0,5,2,0,2,2},
        {0,1,3,2,0,1},
        {0,0,0,2,1,0}
    };
    dijkstra(graph, 0);
    return 0;
}
