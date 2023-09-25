/*
Greetings, Visitor! Welcome to my code, designed to provide you with essential operations on an 
array-based implementation of a stack. Here's what you can do with it:

1. Check if the stack is full.
2. Check if the stack is empty.
3. Push (add) an element onto the stack.
4. Pop (remove) an element from the stack.
5. Retrieve the top element of the stack.

Feel free to explore these fundamental stack operations using my code!
*/

#include<stdio.h>
#define max 100
int stack[max];
int top=-1;

void push(){
    int data;
    printf("Enter the data to insert into the stack\n");
    scanf("%d",&data);
    if(top==max-1){
        printf("Stack Over flow\n");
    }
    else{
        ++top;
        stack[top]=data;
        printf("The data is succefully inserted into the stack\n"); 
    }
}

void pop(){
    int delete_data;
    if(top==-1){
        printf("Stack under flow\n");
    }
    else{
        delete_data=stack[top];
        top--;
        printf("Removed data = %d\n",delete_data);
    }
}

void Top(){
    int top_data;
    top_data = stack[top];
    printf("\nTop data in the stack = %d",top_data);
}

void display(){
    int i;
    if(top>=0){
        printf("The elements in Stacks are : ");
    }
    for(i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
}


int main(){
    int j;
    printf("Enter 1 to push \n");
    printf("Enter 2 to pop\n");
    printf("Enter 3 to dispaly\n");
    printf("Enter 4 to display Top\n");
    printf("ENter 4 to exit\n");
    while(1){
        printf("\nEnter the choice : ");
        scanf("%d",&j);
        if(j==1){
            push();
            continue;
        }
        else if(j==2){
            pop();
            continue;
        }
        else if(j==3){
            display();
            continue;
        }
        else if(j==4){
            Top();
            continue;
        }
        else{
            break;
        }
    }
}
