/* 

Hello, Visitor! Below is my code that facilitates the evaluation of a postfix expression.

-_-_-_-_-  CONCEPT -_-_-_-_-_-

1. Read the expression, and traverse till the end.
2. if it is a number, push it into the stack.
3. if that is an operator take two numbers out of stack
   perform operation with both operand and that operator
   and again push back to stack.
4. Repeat above steps till end. 
5. In the last return the top value of stack as result. 

6. When we subtract the ASCII value of '0' from a digit character, 
   we are essentially converting the character representation of a 
   digit to its corresponding integer value. This is a common technique
   used in programming to convert characters that represent digits to their numerical values.

Hope its clear, Feel free to explore below code to understand better.

*/

#include<stdio.h>
#include<ctype.h>
#include<math.h>


int isOperator(char ch);
int evaluate(char postfix[]);               /* Function declaration */
int perform(int a, int b, char op);

char st[50];
int top = -1;

int isOperator(char ch){            // Function to check if passed character is operator or not.
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%');
}

int evaluate(char postfix[]){
    int i = 0,a,b;
    while(postfix[i] != '\0'){
        if(isdigit(postfix[i])){
            st[++top] = postfix[i] - '0'; // Subtracting zero to convert char to int for performing mathematical operation.
        }
        else if(isOperator(postfix[i])){
            a = st[top];
            top --;
            b = st[top];
            st[top] = perform(b,a,postfix[i]);
        }
        i++;
    }
    return st[top];
}

int perform(int a, int b, char op){     // Function to perform the operation.
    if(op == '+'){
        return a+b;
    }
    else if(op == '-'){
        return a-b;
    }
    else if(op == '*'){
        return a*b;
    }
    else if(op == '/'){
        return a/b;
    }
    else if(op == '%'){
        return a%b;
    }
    else if(op == '^'){
        return pow(a,b);
    }
}

int main(){                 // Main function 
    char postfix[50];
    printf("\nEnter the postfix expression without any spacing : ");
    scanf("%s",postfix);
    int result;
    result = evaluate(postfix);
    printf("\n\tResult = %d\n.",result);
}


