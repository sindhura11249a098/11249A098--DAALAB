#include <stdio.h>
#include <limits.h>
#define V 6
int graph[V][V] = {
    {0,10,0,15,0,0},
    {0,0,0,5,10,0},
    {0,0,0,0,0,10},
    {0,0,0,0,0,5},
    {0,0,0,0,0,10},
    {0,0,0,0,0,0}
};
void bellmanFord(int src) {
    int dist[V];
    int i, u, v;
    // Initialize distances
    for (i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    // Relax edges V-1 times
    for (i = 0; i < V - 1; i++) {
        for (u = 0; u < V; u++) {
            for (v = 0; v < V; v++) {
                if (graph[u][v] != 0 &&
                    dist[u] != INT_MAX &&
                    dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }
    // Check for negative cycle
    for (u = 0; u < V; u++) {
        for (v = 0; v < V; v++) {
            if (graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                printf("Negative cycle exists\n");
                return;
            }
        }
    }
    // Print result
    printf("Vertex\tDistance\n");
    for (i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }
}
int main() {
    bellmanFord(0);
    return 0;
}
