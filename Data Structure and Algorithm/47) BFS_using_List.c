#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node to represent each vertex in the adjacency list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// This struct represents a directed graph using adjacency list representation
typedef struct Graph {
    int V;      // No. of vertices
    Node** adj; // Adjacency list
} Graph;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Graph creator
Graph* createGraph(int V) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = V;

    // Allocate memory for adjacency list
    g->adj = (Node**)malloc(V * sizeof(Node*));
    for (int i = 0; i < V; i++) {
        g->adj[i] = NULL;
    }

    return g;
}

// Function to add an edge to graph
void addEdge(Graph* g, int v, int w) {
    // Add w to v’s list
    Node* newNode = createNode(w);
    newNode->next = g->adj[v];
    g->adj[v] = newNode;
}

// Prints BFS traversal from a given source s
void BFS(Graph* g, int s) {
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

        Node* current = g->adj[s];
        while (current != NULL) {
            int adjacent = current->data;
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                queue[rear++] = adjacent;
            }
            current = current->next;
        }
    }

    free(visited);
    free(queue);
}

int main() {
    int v, input;

    // Get the number of vertices
    printf("\nEnter the no of nodes present in graph: ");
    scanf("%d", &v);

    Graph* g = createGraph(v);

    printf("\n\tTaking graph data\n\nRules to remember : ");
    printf("\n1. Enter the edge b/w nodes one at a time\n2. Enter '-1' when there is no more connection with the current node\n\n");

    for (int i = 0; i < v; i++) {
        while (1) {
            printf("Enter the nodes connected to node %d : ", i + 1);
            scanf("%d", &input);

            if (input == -1) {
                break;
            } else if (input >= 1 && input <= v) {
                addEdge(g, i, input - 1);
            } else {
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
    BFS(g, vertex - 1);

    // Free memory allocated
    for (int i = 0; i < g->V; i++) {
        Node* current = g->adj[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(g->adj);
    free(g);

    printf("\n\n_");
    return 0;
}
