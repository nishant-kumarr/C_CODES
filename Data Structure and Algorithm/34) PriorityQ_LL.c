/*

Hey Visitor ! This is a code of mine that performs functionality of a Priority Queue using list.
Don't forget to check out the concept given at the bottom.

*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

Node* insert(Node* head, int data, int priority){
    Node* newNode = createNode(data, priority);

    if (head == NULL || priority < head->priority){
        newNode->next = head;
        head = newNode;
    } 
    else {
        Node* temp = head;
        while (temp->next != NULL && temp->next->priority <= priority){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

Node* delete(Node* head) {
    if (head == NULL) {
        printf("Priority Queue is empty.\n");
        return head;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

void displayTop(Node* head){
    if (head == NULL){
        printf("Priority Queue is empty.\n");
    } 
    else{
        printf("\nTop element: %d (Priority: %d)\n", head->data, head->priority);
    }
}

void displayAll(Node* head) {
    if (head == NULL) {
        printf("\nPriority Queue is empty.\n");
    } 

    else{
        printf("\nPriority Queue elements:\n");
        Node* current = head;
        while (current != NULL) {
            printf("Data: %d (Priority: %d)\n", current->data, current->priority);
            current = current->next;
        }
    }
}

void displayMenu() {
    printf("\nPriority Queue Menu:\n");
    printf("1. Insert element\n");
    printf("2. Delete top element\n");
    printf("3. Display top element\n");
    printf("4. Display all elements\n");
    printf("5. Stop\n");
}

int main() {
    Node* head = NULL;
    int choice, data, priority;

    displayMenu();

    do {
        for(int i = 0;i<35 ;i++){
            printf("-");
        }
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\tEnter data and priority: ");
                scanf("%d %d", &data, &priority);
                head = insert(head, data, priority);
                break;
            case 2:
                head = delete(head);
                break;
            case 3:
                displayTop(head);
                break;
            case 4:
                displayAll(head);
                break;
            case 5:
                printf("\nThank You.\n\n.");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

/*

------- CONCEPT --------

1. Create Function:
        It creates a new node with the given data and priority.
        Returns a pointer to the newly created node.

2. Insert Function:
        Inserts a new node into the priority queue based on its priority.
        If the queue is empty or the new node has the highest priority, it becomes the new head.
        Otherwise, it traverses the queue to find the correct position for the new node.
        Adjusts the next pointers to maintain the priority order.

3. Delete Function:
        Deletes the top (highest priority) element from the priority queue.
        Adjusts the head pointer to point to the next element in the queue.
        Frees the memory of the deleted node.

4. Display Function:
        Displays the data and priority of the top (highest priority) element in the priority queue.
        or if it need to display all element. then, traverse and keep printing until you reach the end.


    Hope it helped.
*/