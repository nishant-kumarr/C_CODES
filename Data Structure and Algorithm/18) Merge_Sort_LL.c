/*

Hello, Visitor! This is my code that facilitates the execution of a selection sort algorithm on an Linked list.
Feel free to use my codes to understand the core of C Data structure.

*/

#include <stdio.h>
#include <stdlib.h>


typedef struct Node {       // Structure to create linked list.
    int data;
    struct Node* next;
} node;


node* merge(node* left, node* right){           // Function to merge two sorted halves.
    node* result = NULL;

    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    if (left->data <= right->data){
        result = left;
        result->next = merge(left->next, right);
    } 
    else{
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}


node* mergeSort(node* head){                    // Function to sort the passed list.
    if (head == NULL || head->next == NULL){
        return head;
    }

    node* slow = head;
    node* fast = head->next;

    while (fast != NULL) {          // For finding mid.
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    node* left = head;
    node* right = slow->next;
    slow->next = NULL;

    // Recursively sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // Merge the sorted halves
    return merge(left, right);
}

// Function to insert a new node at the end of the linked list
node* insert(node* head, int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Function to print the linked list
void printList(node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;
    int n;

    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements to be sorted: ");
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        head = insert(head, data);
    }

    head = mergeSort(head);

    printf("Sorted list: ");
    printList(head);
    printf("\n\n.");

    return 0;
}
