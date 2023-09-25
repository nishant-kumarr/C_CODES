/* 

Greetings, Visitor! Below, you'll find my code that empowers you to execute a variety of operations on a Doubly Linked List:
1. Create a Doubly Linked List.
2. Display the list's data.
3. Search for specific data within the list.
4. Insert and delete nodes at various positions: beginning, middle, end, a specific location, before, and after a particular location.
5. Delete a node based on a key value.

You might wonder about the purpose of inserting nodes before and after a location when we can use the insertLoc function to 
achieve the same. I'd like to clarify that this was a specific request made to me, and its utility can vary depending on certain 
constraints. Feel free to explore it further!

*/

#include<stdio.h>
#include<stdlib.h>

int n;
struct node *head;
void create_DLL();
void display_DLL();
void search_DLL();
void insertBeg_DLL();
void insertMid_DLL();
void insertEnd_DLL();
void insertLoc_DLL();
void insertBfLoc_DLL();
void insertAfLoc_DLL();
void deleteBeg_DLL();
void deleteMid_DLL();
void deleteEnd_DLL();
void deleteLoc_DLL();
void deleteBfLoc_DLL();
void deleteAfLoc_DLL();
void deletKey_DLL();



struct node {
    struct node *Lnext;
    int data;
    struct node *Rnext;
};

void create_DLL(){
    int i;
    struct node *ptr, *newnode;

    printf("\nEnter no of element in DLL : ");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        if(i==1){
            head = (struct node *)malloc(sizeof(struct node));
            head->Lnext= NULL;
            ptr = head;
        }
        else{
            newnode = (struct node *)malloc(sizeof(struct node));
            ptr->Rnext = newnode;
            newnode->Lnext = ptr;
            ptr = newnode;
        }
        printf("\t\tEnter the node %d data : ",i);
        scanf("%d",&ptr->data);
    }
    ptr->Rnext = NULL;
}

void display_DLL(){
    if(n==0){
        printf("\n\t\t No element in DLL.\n");
    }
    else{
        struct node *ptr1, *ptr2;
        ptr1 = head;

        printf("\nTraversing in forward direction : ");
        while(ptr1 != NULL){
            printf("%d  ",ptr1->data);
            ptr2 = ptr1;
            ptr1 = ptr1->Rnext;
        }
        printf("\nTraversing in Backward direction : ");
        while(ptr2 != NULL){
            printf("%d  ",ptr2->data);
            ptr2 = ptr2->Lnext;
        }
        printf("\n");
    }
}

void search_DLL(){
    int s,flag=0,pos=1;
    printf("\nEnter the value to be searched : ");
    scanf("%d",&s);
    struct node *ptr;
    ptr = head;
    while(ptr!=NULL){
        if(ptr->data==s){
            printf("\n\t\t%d found at position %d",s,pos);
            flag = 1;
        }
        pos++;
        ptr = ptr->Rnext;
    }
    if(flag==0){
        printf("\n\t\t%d is not present in the DLL.",s);
    }
    printf("\n");
}

void insertBeg_DLL(){
    struct node *ptr, *newnode;
    ptr = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value of the node to be inserted : ");
    scanf("%d",&newnode->data);
    newnode->Lnext = NULL;
    newnode -> Rnext = head;
    head->Lnext = newnode;
    head = newnode;
    n = n+1;
    printf("\n\t\t ADDED SUCCESSFULLY\n");
}

void insertMid_DLL(){
    struct node *ptr, *newnode, *ptr2;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value to be added to the newnode : ");
    scanf("%d",&newnode->data);
    int loc = n/2, count = 1;
    ptr = ptr2 = head;
    while(count != loc){
        ptr = ptr->Rnext;
        count ++;
    }
    newnode->Lnext = ptr;
    newnode->Rnext = ptr->Rnext;
    ptr2 = ptr->Rnext;
    ptr -> Rnext = newnode;
    ptr2 -> Lnext = newnode;
    n = n+1;
    printf("\n\t\t ADDED SUCCESSFULLY");
}

void insertEnd_DLL(){
    struct node *ptr, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter value to be added at the newnode : ");
    scanf("%d",&newnode -> data);
    newnode -> Rnext = NULL;

    ptr = head;
    while(ptr->Rnext != NULL){
        ptr = ptr->Rnext;
    }
    newnode->Lnext = ptr;
    ptr->Rnext = newnode;
    n = n+1;
    printf("\n\t\t ADDED SUCCESSFULLY\n");
}

void insertLoc_DLL(){
    struct node *ptr, *newnode, *ptr2;
    int loc,count = 1;
    label : 
    printf("\n\t\tEnter the location : ");
    scanf("%d",&loc);
    if(loc==1){
        insertBeg_DLL();
    }
    else if (loc == n+1){
        insertEnd_DLL();
    }
    else if(loc<0 || loc > n+1){
        printf("\t\t\tInvalid location\n");
        goto label;
    }
    else if(loc > 1 && loc < n+1){
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\t\tEnter the value of the node : ");
        scanf("%d",&newnode->data);

        ptr = head;
        while(count != loc-1){
            ptr = ptr->Rnext;
            count++;
        }
        newnode -> Lnext = ptr;
        newnode -> Rnext = ptr -> Rnext;
        ptr2 = ptr -> Rnext;
        ptr -> Rnext = newnode;
        ptr2 -> Lnext = newnode;
        n = n+1;
        printf("\n\t\t ADDED SUCCESSFULLY\n");
    }
}

void insertBfLoc_DLL(){
    int loc;
    label :
    printf("\tEnter the location : ");
    scanf("%d",&loc);
    if(loc==2){
        insertBeg_DLL();
    }
    else if(loc > n+2 || loc < 2){
        printf("\n\tInvalid location for this task.\n");
        goto label ;
    }
    else if(loc == n+2){
        insertEnd_DLL();
    }
    else{
        int count = 1;
        struct node *ptr, *ptr2, *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\t\tEnter value to the newnode : ");
        scanf("%d",&newnode->data);
        ptr = head;
        while(count != loc){
            ptr2 = ptr;
            ptr = ptr->Rnext;
            count ++;
        }
        ptr2->Rnext = newnode;
        newnode->Lnext = ptr2;
        newnode->Rnext = ptr;
        ptr->Lnext = newnode;
        n = n+1;
        printf("\n\t\t ADDED SUCCESSFULLY.\n");
    }
}

void insertAfLoc_DLL(){
    int loc;
    label:
    printf("\nEnter the Location : ");
    scanf("%d",&loc);
    if(loc==0){
        insertBeg_DLL();
    }
    else if(loc == n){
        insertEnd_DLL();
    }
    else if(loc > n || loc < 0){
        printf("\n\tInvalid Location.\n");
        goto label;
    }
    else{
        int count = 0;
        struct node *ptr, *ptr2, *newnode;
        ptr = head;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\n\tEnter value to the newnode : ");
        scanf("%d",&newnode -> data);
        while(count != loc){
            ptr2 = ptr;
            ptr = ptr->Rnext;
            count ++;
        }
        ptr2->Rnext = newnode;
        newnode->Lnext = ptr2;
        newnode->Rnext = ptr;
        ptr->Lnext = newnode;
        n = n+1;
        printf("\n\t\t ADDED SUCCESSFULLY.\n");
    }
}

void deleteBeg_DLL(){
    if(n==0){
        printf("\n\t\tNO element in DLL.\n");
    }
    else{
        struct node *ptr,*temp;
        temp = head;
        ptr = head->Rnext;
        ptr->Lnext = NULL;
        head = ptr;
        free(temp);
        n = n-1;
        printf("\n\t\t DELETED SUCCESSFULLY\n");
    }
}

void deleteMid_DLL(){
    struct node *ptr,*temp,*temp2;
    int loc = n/2;
    if(n==0){
        printf("\n\t\tNo element in DLL.\n");
    }
    else if(n<=2){
        deleteEnd_DLL();
    }
    else{
        int count = 0;
        ptr = head;
        while(count != loc){
            temp = ptr;
            ptr = ptr->Rnext;
            count++;
        }
        temp -> Rnext = ptr->Rnext;
        temp2 = ptr->Rnext;
        temp2->Lnext = temp;
        free(ptr);
        n = n-1;
        printf("\n\t\t DELETED SUCCESSFULLY\n");
    }
}

void deleteEnd_DLL(){
    if(n==0){
        printf("\n\t\tNo element in DLL.\n");
    }
    else{
        struct node *ptr,*temp;
        ptr = head;
        while(ptr -> Rnext != NULL){
            temp = ptr;
            ptr = ptr -> Rnext;
        }
        temp -> Rnext = NULL;
        free(ptr);
        n = n-1;
        printf("\n\t\t DELETED SUCCESSFULLY.\n");
    } 
}

void deleteLoc_DLL(){
    int loc;
    printf("Enter the location : ");
    scanf("%d",&loc);
    if(n==0){
        printf("\n\t\tNo element in DLL.\n");
    }
    else if(n<3){
        if(loc<1)
        printf("\n\t\tInvalid location.");
        if(loc==1)
        deleteBeg_DLL();
        if(loc==2)
        deleteEnd_DLL();
    }
    else {
        struct node *ptr, *ptr2, *temp;
        int count = 1;
        
        temp = head;
        while(count != loc){
            ptr = temp;
            temp = temp->Rnext;
            count ++;
        }
        ptr->Rnext = temp->Rnext;
        ptr2 = temp->Rnext;
        ptr2->Lnext = ptr;
        free(temp);
        n = n-1;
        printf("\n\t\t DELETED SUCCESSFULLY.\n");
    }
}

void deleteBfLoc_DLL(){
    int loc;
    label:
    printf("\nEnter the location : ");
    scanf("%d",&loc);
    if(loc < 2 || loc > n+1){
        printf("\n\t Invalid Location.\n");
        goto label;
    }
    else if(loc == 2){
        deleteBeg_DLL();
    }
    else if(loc == n+1){
        deleteEnd_DLL();
    }
    else{
        struct node *ptr,*ptr2;
        ptr = head;
        int count = 1;
        while(count != loc-1){
            ptr2 = ptr;
            ptr = ptr->Rnext;
            count ++;
        }
        ptr2->Rnext = ptr->Rnext;
        free(ptr);
        ptr = ptr2->Rnext;
        ptr->Lnext = ptr2;
        n = n-1;
        printf("\n\t DELETED SUCCESSFULLY.\n");
    }
}

void deleteAfLoc_DLL(){
    int loc;
    label : 
    printf("\nEnter the location : ");
    scanf("%d",&loc);
    if(loc < 0 || loc >= n){
        printf("\n\t Invalid Location. Try again !!\n");
        goto label;
    }
    else if(loc == 0){
        deleteBeg_DLL();
    }
    else if(loc == n-1){
        deleteEnd_DLL();
    }
    else{
        int count = 0 ;
        struct node *ptr, *ptr2;
        ptr = head;
        while(count != loc){
            ptr2 = ptr;
            ptr = ptr->Rnext;
            count ++;
        }
        ptr2 -> Rnext = ptr->Rnext;
        free(ptr);
        ptr = ptr2->Rnext;
        ptr->Lnext = ptr2;
        n = n-1;
        printf("\n\t DELETED SUCCESSFULLY.\n");
    }
}

void deletKey_DLL(){
    if(n==0){
        printf("\n\t No element in DLL.\n");
    }
    else{
        int s;
        printf("\n\tEnter the value to be searched and removed : ");
        scanf("%d",&s);
        struct node *ptr, *ptr2;
        label:
        ptr = ptr2 = head;
        if(ptr->data == s){
            deleteBeg_DLL();
            goto label;
        }
        ptr = ptr->Rnext;
        while(ptr->Rnext != NULL){
            if(ptr->data == s){
                ptr2->Rnext = ptr->Rnext;
                free(ptr);
                ptr = ptr2->Rnext;
                ptr->Lnext = ptr2;
                n = n-1;
                printf("\n\t\t DELETED SUCCESSFULLY\n");
                goto label;
            }
            ptr2 = ptr;
            ptr = ptr->Rnext;
        }
        if(ptr->data == s){
            deleteEnd_DLL();
        }
    }
}

int main(){
    int x;
    create_DLL();

    printf("\n01. To dispalay DLL.\n");
    printf("02. To search an element in DLL.\n");
    printf("03. To insert an element at the beginning of DLL.\n");
    printf("04. To insert an element at the end of the DLL.\n");
    printf("05. To insert an element at the mid of the DLL.\n");
    printf("06. To insert an element at any particular location.\n");
    printf("07. To insert an element before a particular location.\n");
    printf("08. To insert an element after a particular location.\n");
    printf("09. To delet the first element of the DLL.\n");
    printf("10. To delet the last element of the DLL.\n");
    printf("11. To delet the mid element of the DLL.\n");
    printf("12. To delet the element from a particular location.\n");
    printf("13. To delet the element before a particular location.\n");
    printf("14. To delet the element after a particular location.\n");
    printf("15. To delet the element using the value of node.\n");

    while(x){

        printf("\nWhat action would you like to perform : choose from options given above \n");
        printf("Enter your choice : ");
        scanf("%d",&x);

        if(x==1){
            display_DLL();
            continue;
        }
        else if(x==2){
            search_DLL();
            continue;
        }
        else if(x==3){
            insertBeg_DLL();
            continue;
        }
        else if(x==4){
            insertEnd_DLL();
            continue;
        }
        else if(x==5){
            insertMid_DLL();
            continue;
        }
        else if(x==6){
            insertLoc_DLL();
            continue;
        }
        else if(x==7){
            insertBfLoc_DLL();
            continue;
        }
        else if(x==8){
            insertAfLoc_DLL();
            continue;
        }
        else if(x==9){
            deleteBeg_DLL();
            continue;
        }
        else if(x==10){
            deleteEnd_DLL();
            continue;
        }
        else if(x==11){
            deleteMid_DLL();
            continue;
        }
        else if(x==12){
            deleteLoc_DLL();
            continue;
        }
        else if(x==13){
            deleteBfLoc_DLL();
            continue;
        }
        else if(x==14){
            deleteAfLoc_DLL();
            continue;
        }
        else if(x==15){
            deletKey_DLL();
            continue;
        }
        else{
            printf("\n\n");
            printf("\t\t_._._. THANK YOU ._._._");
            printf("\n\n $$$");
            break;
        }
    }
    return 0;
}

