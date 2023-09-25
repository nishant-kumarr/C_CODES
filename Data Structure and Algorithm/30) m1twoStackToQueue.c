/* 

Hello, Visitor! This is my code that facilitates the function of a queue using two stacks.

Method 1 : This is method 1 of 2 : making dequeue operation costly.

Note : Second method is also there in repo, do check it out.

Concept : 
The idea is to perform first come first serve operation using stack which basically allow first come last served.
1. To facilitate this idea, we take values into a stack.
2. When it comes to pop we transfer all stack data to another similar stack < lets say temp>. In this way data order gets inverted.
3. Then we pop the top element of temp stack.
4. Then again we move back remaining element of temp stack in original stack making order of element back to the initial order.
5. This method makes DEQUEUE operation costly. That means it takes O(n) complexity. 

Hope cocept is clear, Feel free to explore below code for better understanding.

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *h1 = NULL,*h2 = NULL;


void display(node *head);
node *enqueue();
node *dequeue();

node *enqueue(){
    int choice,i=0;
    node *newnode;
    while(1){
        if(i==0){
            printf("\n");
            i++;
        }
        printf("Enter val to add or press 111 to stop : ");
        scanf("%d",&choice);
        if(choice == 111){
            break;
        }
        else{
            newnode = (node *)malloc(sizeof(newnode));
            newnode -> data = choice;
            newnode ->next = h1;
            h1 = newnode;
        }
    }
}

void display(node *head){
    node *ptr;
    ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

node *dequeue(){
    node *newnode,*ptr;
    h1;
    while(h1 != NULL){
        newnode = (node *)malloc(sizeof(node));
        newnode -> data = h1->data;
        newnode ->next = h2;
        h2 = newnode;
        h1 = h1->next;
    }
    ptr = h2;
    h2 = h2->next;
    free(ptr);
    h1 = NULL;

    while(h2 != NULL){
        newnode = (node *)malloc(sizeof(node));
        newnode->data = h2->data;
        newnode->next = h1;
        h1 = newnode;
        h2 = h2->next;
    }
}

int main(){
    char ch;
    enqueue();
    printf("\nPushed values are : ");
    display(h1);
    dequeue();
    printf("\nAfter Popping once : ");
    display(h1);
    printf("\n\n");
    printf("Enter 'Y' to push again : ");
    scanf(" %c",&ch);
    printf("\n");
    if(ch == 'Y'){
        enqueue();
        printf("\nUpdated values are : ");
        display(h1);
        printf("\n.");
    }
    
    return 0;
}

