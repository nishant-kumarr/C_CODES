/*
Greetings, Visitor! Welcome to my code, designed to provide you with essential operations on an 
Linked-List based implementation of a Circular queue. Here's what you can do with it:

1. Check if Circular queue overflows. Although linked list uses entire memory size but here we've put the constraint to size.
    so, one can change code accordingly while writing their own.
2. Check for Circular queue underflows.
3. Enqueue (add) an element onto the Circular queue.
4. Dequeue (remove) an element from the Circular queue.
5. Retrieve the top element of the Circular queue.

Feel free to explore these fundamental Circular queue operations using my code!
*/


#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;


node *front=NULL,*rear=NULL;
int n=0,c=0;

int enqueue(){
    if(c==n){
        printf("\t\tQueue overflow\n");
        return -1;
    }
    if(front == NULL){
        front = (node*)malloc(sizeof(node));
        rear = front;
    }
    else{
        rear->next = (node*)malloc(sizeof(node));
        rear = rear -> next;
        rear->next = front;
    }
    printf("\tEnter value to node ");
    scanf("%d",&rear->data);
    c++;
}

int dequeue(){
    if(front == NULL){
        printf("\tNo element to delete\n");
    }
    else{
        if(front == rear){
            front = NULL;
            return -1;
        }
        front = front->next;
        c--;
    }
}

void top(){
    if(front == NULL){
        printf("\n No element is there\n");
    }
    else{
        printf("\nTop value of the queue is %d\n",rear->data);
    }
}

void display(){
    if(front == NULL){
        printf("\t\tQueue underflow\n");
    }
    else{
        node *ptr;
        ptr = front;
        printf("\n\tValues of the Queue are : ");
        while(ptr != rear){
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n",ptr->data);
    }
}

int main(){
    printf(" 1. To enter an element\n");
    printf(" 2. To delet an element\n");
    printf(" 3. To display the elements\n");
    printf(" 4. To display the top element\n");

    while(1){
        int x;
        printf("\nEnter the choice : ");
        scanf("%d",&x);

        if(x==1){
            if(n==0){
                printf("\nEnter no of element in the queue : ");
                scanf("%d",&n);
            }
            enqueue();
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
            printf(".\n   THANK YOU   \n.");
            break;
        }
    }
    return 0;
}
