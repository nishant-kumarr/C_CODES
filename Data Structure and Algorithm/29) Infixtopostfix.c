/* 

Hello, Visitor! Below is my code that facilitates the conversion of infix expression to postfix. 

Hope the function of program is clear, Feel free to explore below code to understand better.

CONCEPT USED IN THIS CODE IS GIVEN AT THE BOTTOM OF PROGRAM <scroll down> 

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 100

int precedence(char operator);
int isOperator(char ch);                // Functions declaration
char *convert(char *infix);

int precedence(char operator){          // Function to determine the precedence of operators 
    switch(operator){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default :
            return -1;
    }
}

int isOperator(char ch){                // Function to check if it is a operator or not.
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%');
}


char *convert(char *infix) {            // Function dealing with the conversion.
    int i, j, len, top = -1;
    len = strlen(infix);

    char *postfix = (char *)malloc(sizeof(char) * (len + 2));
    char stack[MAX_SIZE];
    j = 0;

    for (i = 0; i < len; i++) {
        if (infix[i] == ' ' || infix[i] == '\t') {      // if there is any space in expression.
            continue;
        }

        if (isalnum(infix[i])) {            // If it is a number.
            postfix[j++] = infix[i];
        } 
        else if (infix[i] == '(') {         // if it is opening parenthesis.
            stack[++top] = infix[i];
        } 
        else if (infix[i] == ')') {         // if it is closing parenthesis.
            while (top > -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top > -1 && stack[top] != '(') {                // if you encounter imbalanced parenthesis.
                free(postfix);  // Free memory allocated before returning an error.
                return "Invalid Expression";
            }
             else {
                top--;
            }
        } 
        else if (isOperator(infix[i])) {
            while (top > -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }

    while (top > -1) {              // To check : nothing left in stack.
        if (stack[top] == '(') {            // If you encounter imbalanced parenthesis seq.
            free(postfix); // Free memory allocated before returning an error.
            return "Invalid Expression";
        }
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';          // Adding null at the end.
    return postfix;
}


int main(){
    char infix[MAX_SIZE];                               // Main body 
    printf("Enter the infix expression : ");
    scanf("%s",infix);

    char *postfix = convert(infix);

    printf("\n\tEquivalent postfix expression is : %s\n.",postfix);

    return 0;
}



/* -_-_-_-_-_-_  CORE CONCEPT USED -_-_-_-_-_-_-_-

Step 1: Consider the next element in the input.
Step 2: If it is operand, display it.
Step 3: If it is opening parenthesis, insert it on stack.
Step 4: If it is an operator, then
        • If stack is empty, insert operator on stack.
        • If the top of stack is opening parenthesis, insert
            the operator on stack
        • If it has higher priority than the top of stack,
            insert the operator on stack.
        • Else, delete the operator from the stack and
            display it, repeat Step 4.
Step 5: If it is a closing parenthesis, delete the
        operator from stack and display them until an opening
        parenthesis is encountered. Delete and discard the opening
        parenthesis.
Step 6: If there is more input, go to Step 1.
Step 7: If there is no more input, delete the remaining
            operators to output.

    NOTE : Above code is optimized one and their concept for optimisation is not mentioned here.
            Like : Optimizing it for invalid parenthesis sequence or if there is any space or tab 
            in b/w the infix expression.


-_-_-_-_-_-_-_  NISHANT KUMAR - AP22110010245 -_-_-_-_-_-_-_-

*/