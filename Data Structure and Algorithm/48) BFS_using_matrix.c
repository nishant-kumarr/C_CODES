#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 50

// This struct represents a directed graph using
// adjacency list representation
typedef struct Graph_t {
    int V;  // No. of vertices
    bool** adj;
} Graph;

// Graph creator
Graph* Graph_create(int V) {
    Graph* g = malloc(sizeof(Graph));
    g->V = V;

    g->adj = (bool**)malloc(V * sizeof(bool*));
    for (int i = 0; i < V; i++) {
        g->adj[i] = (bool*)malloc(V * sizeof(bool));
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = false;
        }
    }
    return g;
}

// Function to add an edge to graph
void Graph_addEdge(Graph* g, int v, int w) {
    // Add w to v’s list.
    g->adj[v][w] = true;
}

// Prints BFS traversal from a given source s
void Graph_BFS(Graph* g, int s) {
    bool* visited = (bool*)malloc(g->V * sizeof(bool));
    for (int i = 0; i < g->V; i++) {
        visited[i] = false;
    }

    int* queue = (int*)malloc(g->V * sizeof(int));
    int front = 0, rear = 0;

    visited[s] = true;
    queue[rear++] = s;

    while (front < rear) {
        s = queue[front++];
        printf("%d ", s + 1); // Adjusted here to print 1-indexed result

        for (int adjacent = 0; adjacent < g->V; adjacent++) {
            if (g->adj[s][adjacent] && !visited[adjacent]) {
                visited[adjacent] = true;
                queue[rear++] = adjacent;
            }
        }
    }

    free(visited);
    free(queue);
}


int main() {
    int v, input;
    label:
    printf("\nEnter the no of nodes present in graph: ");
    scanf("%d", &v);
    if (v > 50) {
        printf("Currently, at most 50 vertices are allowed, Enter again.");
        goto label;
    }
    Graph* g = Graph_create(v);

    printf("\n\tTaking graph data\n\nRules to remember : ");
    printf("\n1. Enter the edge b/w nodes one at a time\n2. Enter '-1' when there is no more connection with the current node\n\n");

    for (int i = 0; i < v; i++) {
        while (1) {
            printf("Enter the nodes connected to node %d : ", i + 1);
            scanf("%d", &input);

            if (input == -1) {
                break;
            } 
            else if (input >= 1 && input <= v) {
                Graph_addEdge(g, i, input - 1);
            } 
            else {
                printf("Invalid input. Please enter a valid node number.\n");
            }

            // Clear the input buffer
            while ((getchar()) != '\n');
        }
        printf("\n");
    }


    int vertex;
    printf("Enter the vertex from where to start BFS : ");
    scanf("%d", &vertex);
    printf("\nBFS starting from vertex %d : ", vertex);
    Graph_BFS(g, vertex-1);

    // Free memory allocated
    for (int i = 0; i < g->V; i++) {
        free(g->adj[i]);
    }
    free(g->adj);
    free(g);

    printf("\n\n_");
    return 0;
}
