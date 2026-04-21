#include <stdio.h>
#define V 6
#define INF 9999
int capacity[V][V] = {
    {0,8,0,0,3,0},
    {0,0,9,0,0,0},
    {0,0,0,0,7,2},
    {0,0,0,0,0,5},
    {0,0,7,4,0,0},
    {0,0,0,0,0,0}
};
// BFS to find path
int bfs(int parent[], int s, int t) {
    int visited[V] = {0};
    int queue[V], front = 0, rear = 0;
    int i, u;
    queue[rear++] = s;
    visited[s] = 1;
    parent[s] = -1;
    while (front < rear) {
        u = queue[front++];
        for (i = 0; i < V; i++) {
            if (!visited[i] && capacity[u][i] > 0) {
                queue[rear++] = i;
                parent[i] = u;
                visited[i] = 1;
            }
        }
    }
    return visited[t];
}
// Ford-Fulkerson
int maxFlow(int s, int t) {
    int parent[V];
    int max_flow = 0;
    int i;
    while (bfs(parent, s, t)) {
        int path_flow = INF;
        // find minimum capacity
        for (i = t; i != s; i = parent[i]) {
            int u = parent[i];
            if (capacity[u][i] < path_flow)
                path_flow = capacity[u][i];
        }
        // update capacities
        for (i = t; i != s; i = parent[i]) {
            int u = parent[i];
            capacity[u][i] -= path_flow;
            capacity[i][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}
int main() {
    printf("Max Flow: %d\n", maxFlow(0, 5));
    return 0;
}
