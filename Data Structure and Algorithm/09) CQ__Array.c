/*
Greetings, Visitor! Welcome to my code, designed to provide you with essential operations on an 
array-based implementation of a Circular Queue. Here's what you can do with it:

1. Check if the Circular Queue is full.
2. Check if the Circular Queue is empty.
3. Enqueue (add) an element onto the Circular Queue.
4. Dequeue (remove) an element from the Circular Queue.
5. Retrieve the top element of the Circular Queue.

Feel free to explore these fundamental stack operations using my code!
*/


#include<stdio.h>
#define size 3

int CQueue[size], front = -1, rear = -1;

void enqueue(){
    if(front == (rear+1)%size){
        printf("\tQueue overflow !!\n");
    }
    else{
        int n;
        printf("Enter the value to be passed : ");
        scanf("%d",&n);
        if(front == -1){
            front = 0;
        }
        rear = (rear + 1)%size;
        CQueue[rear] = n;
        printf("\t\tAdded Successfully.\n");
    }
}

int dequeue(){
    if(front == -1 && rear == -1){
        printf("\tQueue Underflow\n");
    }
    else{
        printf("\t\tRemoved successfully.\n");
        if(front == rear){
            front = -1;
            rear = -1;
            return -1;
        }
        front = ((front+1)%size);
    }
}

void display(){
    if(front == -1){
        printf("\t\tThere is no element in the Queue.\n");
    }
    else{
        printf("\tElements of CQueue are : ");
        int i;
        i = front;
        while((i +1)%size != (rear+1)%size){
            printf("%d ",CQueue[i]);
            i = (i+1)%size;
        }
        printf("%d",CQueue[rear]);
    }
    printf("\n");
}

void top(){
    if(front == -1){
        printf("\t\tThere is no element in the Queue.\n");
    }
    else{
        printf("\n\tTop element is %d",CQueue[rear]);
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
            printf(".\n   Ended   \n.");
            break;
        }
    }
    return 0;
}