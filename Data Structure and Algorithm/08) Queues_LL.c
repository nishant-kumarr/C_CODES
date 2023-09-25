/*
Greetings, Visitor! Welcome to my code, designed to provide you with essential operations on an 
Linked-List based implementation of a queue. Here's what you can do with it:

1. Check for Queue underflow.
2. Enqueue (add) an element onto the Queue.
3. Dequeue (remove) an element from the Queue.
4. Retrieve the top element of the Queue.

Feel free to explore these fundamental Queue operations using my code!
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *front = NULL;
node *rear = NULL;

void enqueue(int n){
    node *ptr,*newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->data = n;
    newnode->next = NULL;

    if(front == NULL && rear == NULL){
        front = rear = newnode;
    }
    else{
        rear -> next = newnode;
        rear = newnode;
    }
    printf("\tAdded Successfully.\n");
}

int dequeue(){
    if(front == NULL){
        printf("\n\tUnderflow !!");
        return -1;
    }
    else if(front == rear){
        int r;
        r = rear->data;
        free(rear);
        front = rear = NULL;
        printf("\n\t%d Removed",r);
    }
    else{
        int r;
        r = front->data;
        node *temp;
        temp = front;
        front = front->next;
        free(temp);
        printf("\n\t%d Removed",r);
    }
}

void display(){
    if(front == NULL && rear == NULL){
        printf("\tThere is no element in the Queue\n");
    }
    else{
        node *ptr;
        ptr = front;
        printf("\nValues in the Queues are : ");
        while(ptr != rear->next){
            printf("%d",ptr->data);
            ptr = ptr->next;
        }
    }
}

void top(){
    if(front == NULL && rear == NULL){
        printf("\tNo element is there\n");
    }
    else{
        printf("The top value of the Queue is : %d",*rear);
    }
}


int main(){
    printf(" 1. To Enqueue\n");
    printf(" 2. To Dequeue\n");
    printf(" 3. To display\n");
    printf(" 4. To display the Top element\n");

    while(1){
        printf("\nEnter the choice : ");
        int x;
        scanf("%d",&x);
        if(x==1){
            int e;
            printf("Enter the value to enqueue : ");
            scanf("%d",&e);
            enqueue(e);
            continue;
        }
        else if(x==2){
            dequeue();
            continue;
        }
        else if(x==3){
            display();
            continue;
        }
        else if(x==4){
            top();
            continue;
        }
        else{
            printf("\n_-_-_- THANK YOU -_-_-_");
            break;
        }
    }
    return 0;
}