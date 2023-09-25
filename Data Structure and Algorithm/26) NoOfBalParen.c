/* 
Hello, Visitor! Below is my code that helps to count no of valid parenthesis (No of parenthesis with valid pair).

CONCEPT :
1. Take the parenthesis sequence from the user. 
2. Traverse it till the end.
3. If it is a opening parenthesis push it into a stack.
4. If it is a closing parenthesis pop it out of the stack and count it.
5. At last print the count.

Hope its clear , afterall it is simple isn't it, Feel free to explore below code to understand better.
*/

#include<stdio.h>
int main(){
    char s[100],st[100];
    int i,top = -1;
    int count = 0;

    printf("Enter the bracket sequence in one go : ");
    scanf("%s",s);

    for(i=0;s[i]!='\0';i++){
        if(s[i] == '('){
            st[++top] = '(';
        }
        else if(s[i] == ')' && st[top] == '('){
            top--;
            count ++;
        }
    
    }
    
    printf("No of valid bracket sequence present = %d\n\n.",count);

    return 0;
}