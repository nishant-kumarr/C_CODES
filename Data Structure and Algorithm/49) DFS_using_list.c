#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 50

// Node structure for adjacency list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// This struct represents a directed graph using
// adjacency list representation
typedef struct Graph_t {
    int V;  // No. of vertices
    Node** adjList;
} Graph;

// Graph creator
Graph* Graph_create(int V) {
    Graph* g = malloc(sizeof(Graph));
    g->V = V;

    g->adjList = (Node**)malloc(V * sizeof(Node*));
    for (int i = 0; i < V; i++) {
        g->adjList[i] = NULL;
    }
    return g;
}

// Function to add an edge to graph
void Graph_addEdge(Graph* g, int v, int w) {
    // Add w to v’s list.
    Node* newNode = malloc(sizeof(Node));
    newNode->data = w;
    newNode->next = g->adjList[v];
    g->adjList[v] = newNode;
}

// DFS helper function
void DFSUtil(Graph* g, int v, bool* visited) {
    visited[v] = true;
    printf("%d ", v + 1); // Adjusted here to print 1-indexed result

    // Traverse the adjacency list of the current vertex
    Node* temp = g->adjList[v];
    while (temp != NULL) {
        int adjacent = temp->data;
        if (!visited[adjacent]) {
            DFSUtil(g, adjacent, visited);
        }
        temp = temp->next;
    }
}

// DFS traversal
void Graph_DFS(Graph* g, int s) {
    bool* visited = (bool*)malloc(g->V * sizeof(bool));
    for (int i = 0; i < g->V; i++) {
        visited[i] = false;
    }

    DFSUtil(g, s, visited);

    free(visited);
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
    printf("Enter the vertex from where to start DFS : ");
    scanf("%d", &vertex);
    printf("\nDFS starting from vertex %d : ", vertex);
    Graph_DFS(g, vertex-1);

    // Free memory allocated
    for (int i = 0; i < g->V; i++) {
        Node* current = g->adjList[i];
        while (current != NULL) {
            Node* next = current->next;
            free(current);
            current = next;
        }
    }
    free(g->adjList);
    free(g);

    printf("\n\n_");
    return 0;
}
