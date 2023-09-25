/*
Greetings, Visitor! Welcome to my code, designed to provide you with essential operations on an 
Linked-List based implementation of a stack. Here's what you can do with it:

1. Check for stack overflow. Although in case of stack it takes entire memory size but here we've constraint it. 
    One can modify as per their requirement.
2. Check for stack underflow.
3. Push (add) an element onto the stack.
4. Pop (remove) an element from the stack.
5. Retrieve the top element of the stack.

Feel free to explore these fundamental stack operations using my code!
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top = NULL;

int max=0,n=0;

void push(int item){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode -> next = top;
    top = newnode;
    n++;
}

int pop(){
    if(top == NULL){
        return 0;
    }
    int item = top->data;
    struct node *temp;
    temp = top;
    top = top->next;
    free(temp);
    printf("\nOne item popped out.\n");
    return item;
    
}

void display(){
    if(top == NULL){
        printf("Stack underflow.");
    }
    else{
        struct node *temp;
        temp = top;
        printf("Stacks element are : ");
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp -> next;
        }
    }
    printf("\n");
}

void Top(){
    if(top == NULL){
        printf("Stack underflow.");
    }
    else{
        printf("Top value is : %d",top->data);
    }
    printf("\n");
}

int main(){
    int x;
    printf("Enter - 1 To push.\n");
    printf("Enter - 2 To pop.\n");
    printf("Enter - 3 To display.\n");
    printf("Enter - 4 To display the top.\n");

    while(1){
        printf("\nEnter the choice : ");
        scanf("%d",&x);
        if(x==1){
            if(max==0){
                printf("Enter the no of element : ");
                scanf("%d",&max);
                goto label2;
            }
            if(n==max){
                printf("Stack overflow. Can't add anymore element.\n");
                goto label;
            }
            else{
                label2:
                int data;
                printf("Enter data to push : ");
                scanf("%d",&data);
                push(data);
                continue;
            }
            label:
        }
        else if(x==2){
            pop();
            continue;
        }
        else if(x==3){
            display();
            continue;
        }
        else if(x==4){
            Top();
            continue;
        }
        else{
            break;
        }
    }

}