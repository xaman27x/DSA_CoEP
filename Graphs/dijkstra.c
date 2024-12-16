#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int findMin(int* weight, bool visited[], int V) {
    int min_value = INT_MAX, min_index;
    for(int i = 0; i < V; i++) {
        if(weight[i] < min_value && !visited[i]) {
            min_value = weight[i];
            min_index = i;
        }
    }
    return min_index;
}


void printShortestPath(int* weight, int src, int V) {
    for(int i = 0; i < V; i++) {
        printf("%d -> %d = %d\n", src, i, weight[i]);
    };
}

// O(V^2) Approach, which can be optimized to O(VLogV) using a Priority Queue to get the minimum element
void dijkstra(int graph[][9], int V, int src) {
    int* weight = (int*) malloc(sizeof(int) * V);
    bool* visited = (bool*) malloc(sizeof(bool) * V);

    for(int i = 0; i < V; i++) {
        weight[i] = INT_MAX;
        visited[i] = false;
    }
    weight[src] = 0;

    for(int count = 0; count < V - 1; count++) {
        int u = findMin(weight, visited, V);
        visited[u] = true;

        for(int v = 0; v < V; v++) {
            if(!visited[v] && graph[u][v] && weight[u] != INT_MAX && weight[u] + graph[u][v] < weight[v]) {
                weight[v] = weight[u] + graph[u][v];
            }
        }
    }
    printShortestPath(weight, src, V);
    free(weight);
    free(visited);
}

int main() {
    int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    dijkstra(graph, 9, 0);
    return 0;
}