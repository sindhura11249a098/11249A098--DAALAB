#include <stdio.h>
#include <stdlib.h>
#define V 4
#define E 5
// Find parent
int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}
// Union
void unite(int parent[], int u, int v) {
    int p1 = find(parent, u);
    int p2 = find(parent, v);
    parent[p1] = p2;
}
// Sort edges by weight
int compare(const void *a, const void *b) {
    return ((int*)a)[2] - ((int*)b)[2];
}
int main() {
    int edges[E][3] = {
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
    };
    int parent[V];
    int i, cost = 0;
    // Initialize parent
    for (i = 0; i < V; i++)
        parent[i] = i;
    // Sort edges
    qsort(edges, E, sizeof(edges[0]), compare);
    printf("Following are the edges in the constructed MST\n");
    // Kruskal
    for (i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        if (find(parent, u) != find(parent, v)) {
            unite(parent, u, v);
            printf("%d -- %d == %d\n", u, v, w);
            cost += w;
        }
    }
    printf("Minimum Cost Spanning Tree: %d\n", cost);
    return 0;
}
