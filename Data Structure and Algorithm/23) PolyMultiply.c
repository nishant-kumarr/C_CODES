/* 

Hello, Visitor! Below is my code that facilitates the execution of single variable polynomial multiplication.

CONCEPTS : 
1. Take two polynomial (either in sorted order of power or sorted them after taking) in two differnt linked list.
2. Then multiply each term of first polynomail one by one with all the terms of second and store result in new linked list.
3. Multiplication will be done as : add the power and multiply the coefficient.  
4. Then combine all the terms with same power.
5. Then sort them in them particular order, In this code we've used merge sort algorithm.
6. and finally print the resultant linked list.

Hope its clear, Feel free to explore below code to understand better.

*/

#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int coef;
    int pow;
    struct node *next;
}node;


node *h1, *h2, *h3;         
node *create();
void display(node *head, char var);             /* SOME GLOBAL DECLARATIONS */
node *multiply(node *h1, node *h2);
node *combineTerms(node *head);
node *mergeSort(node *head);
node *merge(node *left, node *right);
node *findMiddle(node *head);


node *create(){         /* FUNCTION TO CREATE POLYNOMIALS AND TAKE THEIR DATA */
    node *ptr,*newnode;
    int i=1;
    int choice; 
    while(1){
        printf("\nPress 111 to stop else 222 to continue : \n");
        scanf("%d",&choice);
        if(choice == 111){
            break;
        }
        if(i==1){
            newnode = (node *)malloc(sizeof(node));
            newnode -> next = NULL;
            ptr = newnode;
            printf("Enter the coefficient  : ");
            scanf("%d",&newnode->coef);
            printf("Enter the power : ");
            scanf("%d",&newnode->pow);
            i++;
        }
        else{
            newnode = (node *)malloc(sizeof(node));
            printf("Enter the coefficient  : ");
            scanf("%d",&newnode->coef);
            printf("Enter the power : ");
            scanf("%d",&newnode->pow);
            newnode->next = ptr;
            ptr = newnode;
        }
    }
    return ptr;
}


void display(node *head,char var){      /* FUNCTION TO PRINT THE POLYNOMIALS */
    node *ptr;
    ptr = head;
    while(ptr != NULL)
    {   
        if(ptr->coef != 0){
            printf("%d",ptr->coef);
        }
        if(ptr->pow != 0 && ptr->coef != 0){
            printf("%c^",var);
            printf("%d",ptr->pow);
        }
        if(ptr->next != NULL){
            printf(" + ");
        }
        ptr = ptr->next;
    }
}


node *multiply(node *h1, node *h2) {        /* FUNCTION TO MULTIPLY THE POLYNOMIALS */
    node *result = NULL;
    
    for (node *curr1 = h1; curr1 != NULL; curr1 = curr1->next) {
        for (node *curr2 = h2; curr2 != NULL; curr2 = curr2->next) {
            node *newnode = (node *)malloc(sizeof(node));
            newnode->next = result;
            result = newnode;
            
            newnode->pow = curr1->pow + curr2->pow;
            newnode->coef = curr1->coef * curr2->coef;
        }
    }
    
    return result;
}


node *combineTerms(node *head) {        /* FUNCTION TO COMBINE TERMS */
    node *current = head;
    
    while (current != NULL) {
        node *runner = current;
        while (runner->next != NULL) {
            if (runner->next->pow == current->pow) {
                current->coef += runner->next->coef;
                node *temp = runner->next;
                runner->next = temp->next;
                free(temp);
            } 
            else {
                runner = runner->next;
            }
        }
        
        current = current->next;
    }
    return head;
}


node *mergeSort(node *head){                    /* FUNCTION FOR SORTING AFTER MULTIPLICATION */
    if(head == NULL || head->next == NULL){
        return head;
    }
    node *middle;
    middle = findMiddle(head);
    node *left = head;
    node *right = middle->next;
    middle->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left,right);
}


node *merge(node *left , node *right){         /* FUNCTION NEEDED BY MERGE SORT TO MERGE SUB MERGED UNITS*/
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }
    node *result;
    if(left->pow <= right->pow){
        result = left;
        result->next = merge(left->next,right);
    }
    else{
        result = right;
        result->next = merge(left,right->next);
    }
    return result;
}


node *findMiddle(node *head){                   /* FUNCTION TO FIND MIDDLE OF A LINKED LIST NEEDED BY MERGE SORT */
    node *ptr1 = head, *ptr2 = head;
    while(ptr2->next != NULL && ptr2->next->next != NULL){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
    }
    return ptr1;
}


int main(){ 
    printf("\n\t\tENTER EQUATION 1 PUT EQUATION IN PARTICULAR OF POWER : ");
    printf("\n");
    h1 = create();
    printf("\n\t\tENTER EQUATION 2 PUT EQUATION IN SAME ORDER AS OF EQN 1 : ");
    printf("\n");
    h2 = create();
    char var;
    printf("Enter the variable : ");
    scanf(" %c",&var);
    printf("\nThe first equation is : ");
    display(h1,var);                            /* MAIN BODY DEALING WITH DIFFERENT SUBTASKS*/
    printf("\nThe second equation is : ");
    display(h2,var);
    printf("\n");
    h3 = multiply(h1,h2);
    h3 = combineTerms(h3);
    h3 = mergeSort(h3);
    printf("The multiplied equation is : ");
    display(h3,var);
    printf("\n\n.");
    return 0;
}

