#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H
#include <stdbool.h>

// Structure for the graph
struct Graph {
    int V;               // Number of vertices
    int E;               // Number of edges
    int** matrix;        // Adjacency matrix
};

// Function prototypes
struct Graph* createGraph(int V);
void addEdge(struct Graph* graph, int src, int dest, bool isDirected);
void displayGraph(struct Graph* graph);
void freeGraph(struct Graph* graph);

#endif
