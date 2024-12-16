#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// Create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = 0;

    graph->matrix = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->matrix[i] = (int*)calloc(V, sizeof(int));
    }

    return graph;
}

// Add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest, bool isDirected) {
    if (src < 0 || src >= graph->V || dest < 0 || dest >= graph->V) {
        printf("Invalid vertices: %d -> %d\n", src, dest);
        return;
    }

    graph->matrix[src][dest] = 1;  // Add edge from src to dest
    if (!isDirected) {
        graph->matrix[dest][src] = 1;  // Add edge from dest to src for undirected graph
    }

    graph->E++;
}

// Display the graph
void displayGraph(struct Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);
}
