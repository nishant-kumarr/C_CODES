/* 

Hello, Visitor! Below is my code that helps to figure out what to put at the place of question mark so that 
sequence becomes valid.

For example : if the user gives the sequence ((??)) then, program to should return valid sequence ((()))

Hope the question is clear. 
Feel free to explore the code below.

*/

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

void replaceQuestionMarks(char *sequence){
    int len = strlen(sequence);
    int openCount = 0;
    
    for (int i = 0; i < len; i++) {
        if (sequence[i] == '(') {
            openCount++;
        } else if (sequence[i] == ')') {
            if (openCount > 0) {
                openCount--;
            } else {
                sequence[i] = '(';
            }
        }
    }
    
    for (int i = len - 1; i >= 0; i--) {
        if (openCount > 0 && sequence[i] == '(') {
            openCount--;
            sequence[i] = ')';
        }
    }
}

int main() {
    char sequence[MAX_LEN];
    
    printf("Enter a sequence of parenthesis with question marks: ");
    scanf("%s", sequence);
    
    int len = strlen(sequence);
    int openCount = 0;
    int closeCount = 0;
    
    for (int i = 0; i < len; i++) {
        if (sequence[i] == '(') {
            openCount++;
        } 
        else if (sequence[i] == ')') {
            if (openCount > 0) {
                openCount--;
            } else {
                sequence[i] = '(';
            }
        } 
        else {  // Question mark
            if (openCount > closeCount) {
                sequence[i] = ')';
                closeCount++;
            } else {
                sequence[i] = '(';
                openCount++;
            }
        }
    }
    
   
    replaceQuestionMarks(sequence);
    
    printf("\n\tFinal sequence: %s\n.", sequence);
    
    return 0;
}
