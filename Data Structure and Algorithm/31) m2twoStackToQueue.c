/* 

Hello, Visitor! This is my code that facilitates the function of a queue using two stacks.

Method 2 : This is 2nd method of total 2 methods : making Enqueue operation costly.

Note : First method is also there in repo, do check it out.

Concept : 
The idea is to perform first come first serve operation using stack which basically allow first come last served.
1. To fascilitate this idea, what we do is if it is the first element of stack (when top == -1) push it into the stack.
2. Else if it is not, then, first transfer all the element of stack in another similar stack (lets say temp).
3. After transfering all the elements, original stack will be vacant then, push the element into that vacant original stack.
4. After pushing value, retrieve all the previous values from the temp stack. This way every time values added gets to the bottom.
5. Now, when it comes to pop, just pop the top element of stack.
6. So, here this method makes enqueue operation costly that is O(n) complexity, unlike method 1 that makes dequeue costly.

Hope cocept is clear, Feel free to explore below code for better understanding.

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *h1 = NULL,*h2 = NULL;                
int i=1;

void display(node *head);
node *enqueue();
node *dequeue();

node *enqueue(){
    int choice;
    node *newnode;
    while(1){
        printf("Enter value to be enqueue or enter 111 to stop : ");
        scanf("%d",&choice);
        if(i==1){
            if(choice == 111){
                break;
            }
            newnode = (node *)malloc(sizeof(node));
            newnode->data = choice;
            newnode->next = h1;
            h1 = newnode;
            i++;
        }
        else{
            if(choice == 111){
                break;
            }
            while(h1 != NULL){
                newnode = (node*)malloc(sizeof(node));
                newnode->data = h1->data;
                newnode ->next = h2;
                h2 = newnode;
                h1 = h1->next;
            }
            newnode = (node *)malloc(sizeof(node));
            newnode->data = choice;
            newnode->next = h1;
            h1 = newnode;
            while(h2 != NULL){
                newnode = (node*)malloc(sizeof(node));
                newnode->data = h2 -> data;
                newnode->next = h1;
                h1 = newnode;
                h2 = h2->next;
            }
        }
    }
    return h1;
}

node *dequeue(){
    node *ptr;
    ptr = h1;
    h1 = h1->next;
    free(ptr);
}

void display(node *head){
    node *ptr;
    ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    char ch;
    enqueue();
    printf("\nPushed values are : ");
    display(h1);
    printf("\n%d",h1->data);
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