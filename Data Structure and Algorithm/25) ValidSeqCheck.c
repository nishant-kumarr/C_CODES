/*

Hello, Visitor! Below is my code that facilitates the execution for checking if the bracket sequence is valid or not.
      
      -_-_-_ CONCEPT _-_-_-_- 

1) Read the input sequence and traverse it from left to right 
2) If the i-th character is open symbol then, push it to the stack.
3) If the i-th character is closed.
    i) if stack is empty , print Invalid.
    ii) if the stack is non-empty & entered character is not opposite to 
        the character on the top of stack. print Invalid.
    iii) if above two conditions are false pop the stack.
4) Repeat the above steps till complete traversal after that if stack is empty 
    print valid. if stack is not empty - sequence is invalid.

Hope its clear, Feel free to explore below code to understand better.

*/

#include<stdio.h>
int main(){
    char s[100], st[100];
    int i,top = -1;
    printf("Enter the bracket sequence in one go : ");
    scanf("%s",s);

    for(i=0; s[i] != '\0'; i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st[++top] = s[i];
        }
        else{
            if(top == -1){
                printf("\nInvalid\n\n.");
                return 0;
            }
            else if((s[i] == ')' && st[top] != '(') || 
                    (s[i] == '}' && st[top] != '{') || 
                    (s[i] == ']' && st[top] != '[')){
                printf("\nInvalid\n\n.");
                return 0;
            }
            else{
                top --;
            }
        }
    }
    if(top == -1){
        printf("\nValid\n\n.");
    }
    else{
        printf("\nInvalid\n\n.");
    }

    return 0;
}

