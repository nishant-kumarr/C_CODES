/* 
THIS PROGRAM WILL TWO VERY LARGE NUMBERS THAT ARE BEYON THE SCOPE OF LONG LONG USING LINKED LIST.
for example two number each having 25 digits. 

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{        /* DEFINING A NODE */
    int data;               
    struct node *next;
} node;

node *h1;           /* SOME GLOBAL POINTERS */
node *h2;
node *h3;

node *create(){         /* FUNCTION TO CREATE A LINKED LIST */
    int i=1,val;
    node *ptr,*head;

    while(1){
        printf("Enter the value or press 111 to end : ");
        scanf("%d",&val);
        if(val == 111){
            break;
        }
        if(i==1){
            head = (struct node *)malloc(sizeof(struct node));
            i++;
            ptr = head;
        }
        else{
            ptr -> next = (struct node *)malloc(sizeof(struct node));
            ptr = ptr -> next;
        }
        ptr->data = val;
    }
    ptr -> next = NULL;
    return head;
}

void display(node *head){           /* FUNCTION TO DISPLAY A LINKED LIST */
    node *ptr;
    ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

node *add(node *h1, node *h2) {             /* FUNCTION TO ADD TWO LINKED LISTS*/
    int c = 0;      
    node *ptr, *head;
    head = (node *)malloc(sizeof(node));
    head->next = NULL; // Initialize the next pointer of the head node
    ptr = head;
    
    while (h1 != NULL || h2 != NULL || c != 0) { // Consider carry (c) even if both lists are exhausted
        int sum = c;
        if (h1 != NULL) {
            sum += h1->data;
            h1 = h1->next;
        }
        if (h2 != NULL) {
            sum += h2->data;
            h2 = h2->next;
        }

        c = sum / 10;
        ptr->next = (node *)malloc(sizeof(node));
        ptr = ptr->next;
        ptr->data = sum % 10;
        ptr->next = NULL;
    }
    
    return head->next; // Return the actual result list (skip the dummy head node)
}

node *reverse(node *head) {         /* FUNCTION TO REVERSE A GIVEN NUMBER */
    node *prev = NULL;
    node *current = head;
    node *nextNode = NULL;

    while (current != NULL){
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev; 

}

int main(){                     /* TAKING TWO NUMBERS PRINTING THE ORIGINAL NUMBERS */
    printf("Enter the first  number");      /* THEN REVERSE IT AND ADD */
    printf("\n");                               /* THEN REVERSE THE RESULT AND PRINT IT. */
    h1 = create();
    printf("Enter the second number");
    printf("\n");
    h2 = create();
    printf("\n\t\tList one is : ");
    display(h1);
    printf("\n\t\tList two is : ");
    display(h2);
    h1 = reverse(h1);
    h2 = reverse(h2);
    h3 = add(h1,h2);
    h3 = reverse(h3);
    printf("\n\tAfter addition number = ");
    display(h3);
    return 0;
}