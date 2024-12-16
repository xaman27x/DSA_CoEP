#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

// Utility Function
int minKey(int* key, bool mstSet[], int V) {
    int min = INT_MAX, min_index = -1;

    for(int v = 0; v < V; v++) {
        if(!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[][5], int V) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

void primMST(int graph[][5], int V) {
    int* parent = (int*) malloc(V * sizeof(int)); // Constructed MST
    int* key = (int *) malloc(V * sizeof(int));   // To pick the minimum weight
    bool* mstSet = (bool*) malloc(V * sizeof(bool)); // Check MST Inclusion

    for(int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;

    for(int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for(int v = 0; v < V; v++) {
            if(graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph, V);

    free(parent);
    free(key);
    free(mstSet);
}

int main() {
    int graph[5][5] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

    primMST(graph, 5);

    return 0;
}
