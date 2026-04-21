#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define V 5
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, index = -1;
    int i;\
    for (i = 0; i < V; i++) {
        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            index = i;
        }
    }
    return index;
}
void prim(int graph[V][V]) {
    int parent[V];
    int key[V];
    bool mstSet[V];
    int i, count, v, u;
    // Initialize
    for (i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    // Build MST
    for (count = 0; count < V - 1; count++) {
        u = minKey(key, mstSet);
        mstSet[u] = true;
        for (v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    // Print MST
    printf("Edge\tWeight\n");
    for (i = 1; i < V; i++) {
        printf("%d - %d\t%d\n", parent[i], i, graph[parent[i]][i]);
    }
}
int main() {
    int graph[V][V] = {
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0}
    };
    prim(graph);
    return 0;
}
