/*

Hello, Visitor! Below is my code that facilitates the execution of single variable polynomial addition.

CONCEPT : 
1. Take two polynomials and store them in separate linked list.
2. Traverse until both ends.
3. Before that EITHER take polynomial in sorted order of power ELSE sorted them.
4. Now, while traversing compare power if they are equal add and store in third polynomial else
    store the highest power.
5. If power was equal in last step then increment both polynomial else increment the polymial of highest power.
6. Keep going till the end.
7. Suppose if one polynomial got more term than other then, keep taking and storing the values from larger polynomial
    in resultant polynomial.
8. When both reaches end stop adding and print the resultant polynomial.

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

node *create(){     /* FUNCTION TO DEAL WITH CREATION OF POLYNOMIALS */
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

void display(node *head,char var){      /* FUNCTION TO DISPLAY POLYNOMIALS */
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

node *add(node *h1, node *h2){      /* FUNCTIONS TO ADD THE POLYNOMIALS */
    node *ptr,*newnode; 
    int i=1;
    while(h1 != NULL || h2 != NULL)
    {
        if(i==1)
        {
            newnode = (node *)malloc(sizeof(node));
            newnode->next = NULL;
            ptr = newnode;
            i++;
        }
        else
        {
            newnode = (node *)malloc(sizeof(node));
            newnode->next = ptr;
            ptr = newnode;
        }

        if(h1 != NULL && h2 != NULL)        /* WHEN BOTH POLYNOMIAL HAVE EQUAL NO OF TERMS */
        {
            if(h1->pow == h2->pow){
                newnode->pow = h1->pow;
                newnode->coef = (h1->coef + h2->coef);
                h1 = h1->next;
                h2 = h2->next;
            }
            else if(h1->pow < h2->pow){     /* IF ELIF CONDITIONS DEALING WITH POWERS */
                newnode->pow = h2->pow;
                newnode->coef = h2->coef;
                h2 = h2->next;
            }
            else if(h1->pow > h2->pow){
                newnode->pow = h1->pow;
                newnode -> coef = h1->coef;
                h1 = h1->next;
            }
        }
        else if(h1 != NULL && h2 == NULL){      /* WHEN 2ND POLYNOMIAL HAS MORE TERMS THAN THE 1ST */
            newnode -> pow = h1->pow;
            newnode -> coef = h1->coef;
            h1 = h1->next;
        }
        else if(h1 == NULL && h2 != NULL){      /* WHEN 1ST POLYNOMIAL HAS MORE TERMS THAN THE 2ND */
            newnode -> pow = h2->pow;
            newnode-> coef = h2->coef;
            h2 = h2->next;
        }
    }

    return ptr;
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
    display(h1,var);                                /* TAKE EQUATIONS - (COEFF, POWER AND VARIABLE) - ADD AND PRINT */
    printf("\nThe second equation is : ");
    display(h2,var);                                /* NOTE THAT THIS PROGRAM DEALS WITH SINGLE VARIABLE POLYNOMIALS ONLY*/
    printf("\n");
    h3 = add(h1,h2);
    printf("The added equation is : ");
    display(h3,var);

    printf("\n\n.");
    return 0;
}


/* SUBMITTED BY -   NISHANT KUMAR  */