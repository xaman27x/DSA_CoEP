#ifndef GRAPH_ADJLIST_H
#define GRAPH_ADJLIST_H

#include <stdbool.h>

// Structure for an adjacency list node
struct AdjListNode {
    int dest;                       // Destination vertex
    struct AdjListNode* next;       // Pointer to the next node
};

// Structure for an adjacency list
struct AdjList {
    struct AdjListNode* head;       // Pointer to the head of the list
};

// Structure for the graph
struct Graph {
    int V;                          // Number of vertices
    struct AdjList* array;          // Array of adjacency lists
};

// Function prototypes
struct Graph* createGraph(int V);
void addEdge(struct Graph* graph, int src, int dest);
void displayGraph(struct Graph* graph);
void freeGraph(struct Graph* graph);

#endif
