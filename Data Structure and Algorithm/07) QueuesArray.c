/*
Greetings, Visitor! Welcome to my code, designed to provide you with essential operations on an 
array-based implementation of a Queue. Here's what you can do with it:

1. Check if the queue is full.
2. Check if the queue is empty.
3. Enqueue (add) an element onto the queue.
4. Dequeue (remove) an element from the queue.
5. Retrieve the top element of the queue.

Feel free to explore these fundamental stack operations using my code!
*/

#include<stdio.h>
#define n 5
int front = -1, rear = -1;
int queue[n];

void enqueue();
void dequeue();
void display();
void top();

void enqueue(){
    if(rear == n-1){
        printf("\nQueue is Full.");
        return;
    }
    int val;
    printf("Enter the value : ");
    scanf("%d",&val);
    front = 0;
    rear ++;
    queue[rear] = val;
    printf("\tAdded successfully.");
}

void dequeue(){
    if(front == -1){
        printf("\tQueue is empty.");
    }
    else{
        printf("\tDeleted successfully.\n\tDeleted element is %d",queue[front]);
        front ++;
        if(front == n){
            front = rear = -1;
        }
    }
}

void display(){
    if(front == -1){
        printf("\nQueue is empty.");
    }
    else{
        int i;
        printf("\tQueues elements are : ");
        for(i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
    }
}


void top(){
    if(front == -1){
        printf("\nQueue is empty");
    }
    else{
        printf("\tTop value of Array is %d",queue[rear]);
    }
}


int main(){
    int x;
    printf("Enter 1 to Push : \n");
    printf("Enter 2 to Pop : \n");
    printf("Enter 3 to Display : \n");
    printf("Enter 4 to display the Top : \n");

    while(1){
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
            break;
        }
    }
}