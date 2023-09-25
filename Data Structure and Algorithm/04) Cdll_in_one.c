/* 

Greetings, Visitor! Below, you'll find my code that empowers you to execute a variety of operations on a Cirularly doubly Linked List:
1. Create a Cirularly doubly Linked List.
2. Display the list's data.
3. Search for specific data within the list.
4. Insert and delete nodes at various positions: beginning, middle, end, a specific location, before, and after a particular location.
5. Delete a node based on a key value.

You might wonder about the purpose of inserting nodes before and after a location when we can use the insertLoc function to 
achieve the same. I'd like to clarify that this was a specific request made to me, and its utility can vary depending on certain 
constraints. Feel free to explore it further!

*/


#include<stdio.h>
#include <stdlib.h>

int n;
struct node *head;
void create_CDLL();
void display_CDLL();
void search_CDLL();
void insertBeg_CDLL();
void insertEnd_CDLL();
void insertMid_CDLL();
void insertLoc_CDLL();
void insertBfLoc_CDLL();
void insertAfLoc_CDLL();
void deletBeg_CDLL();
void deletEnd_CDLL();
void deletMid_CDLL();
void deletLoc_CDLL();
void deletBfLoc_CDLL();
void deletAfLoc_CDLL();
void deletKey_CDLL();


struct node {
    struct node *Lnext;
    int data;
    struct node *Rnext;
};

void create_CDLL(){
    printf("\n Enter no of elements in CDLL : ");
    scanf("%d",&n);
    int i;
    struct node *ptr, *newnode;
    for(i=1;i<=n;i++){
        if(i==1){
            head = (struct node *)malloc(sizeof(struct node));
            ptr = head;
        }
        else{
            newnode = (struct node *)malloc(sizeof(struct node));
            ptr -> Rnext = newnode;
            newnode->Lnext = ptr;
            ptr = newnode;
        }
        printf("\t\t Enter the value of node %d : ",i);
        scanf("%d",&ptr->data);
    }
    ptr -> Rnext = head;
    head->Lnext = ptr;
}

void display_CDLL(){
    if(n==0){
        printf("\n\t\tNo elements in CDLL.\n");
    }
    else{
        struct node *ptr;
        ptr = head;
        printf("\n\t\t Elements of CDLL are : ");
        printf("%d  ",ptr->data);
        ptr = ptr->Rnext;
        while(ptr != head){
            printf("%d  ",ptr->data);
            ptr = ptr->Rnext;
        }
    }
}

void search_CDLL(){
    struct node *ptr;
    int s,flag=0,count=1;
    ptr = head;
    printf("\tEnter the Value to be searched : ");
    scanf("%d",&s);
    if(ptr->data == s){
        printf("\t\t%d found at position %d.\n",s,count);
        flag = 1;
    }
    ptr = ptr->Rnext;
    count ++;
    while(ptr != head){
        if(ptr->data == s){
            printf("\t\t%d found at position %d.\n",s,count);
            flag = 1;
        }
        count ++;
        ptr = ptr-> Rnext;
    }
    if(flag==0){
        printf("\t\t%d is not present in the CDLL.\n",s);
    }
}

void insertBeg_CDLL(){
    struct node *ptr, *newnode;
    ptr = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\t\tEnter value to the node : ");
    scanf("%d",&newnode->data);
    newnode->Rnext = ptr;
    ptr->Lnext = newnode;
    while(ptr->Rnext != head){
        ptr = ptr -> Rnext;
    }
    ptr->Rnext = newnode;
    head = newnode;
    n = n+1;
    printf("\n\t\tADDED SUCCESSFULLY.\n");
}

void insertEnd_CDLL(){
    struct node *ptr, *newnode;
    ptr = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\t\tEnter value to the node : ");
    scanf("%d",&newnode->data);
    while(ptr->Rnext != head){
        ptr = ptr->Rnext;
    }
    ptr->Rnext = newnode;
    newnode->Lnext = ptr;
    newnode->Rnext = head;
    n = n+1;
    printf("\n\t\tADDED SUCCESSFULLY.\n");
}

void insertMid_CDLL(){
    int count = 1;
    struct node *ptr, *newnode;
    ptr = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\t\tEnter the value of newnode : ");
    scanf("%d",&newnode->data);
    while(count != n/2){
        ptr = ptr->Rnext;
        count ++;
    }
    newnode -> Lnext = ptr;
    newnode -> Rnext = ptr -> Rnext;
    ptr -> Rnext = newnode;
    ptr = ptr->Rnext;
    ptr->Lnext = newnode;
    n = n+1;
    printf("\n\t\tADDED SUCCESSFULLY.\n");
}

void insertLoc_CDLL(){
    int loc;
    label :
    printf("\t\tEnter the location : ");
    scanf("%d",&loc);
    if(loc==1){
        insertBeg_CDLL();
    }
    else if(loc==n){
        insertEnd_CDLL();
    }
    else if(loc<0 || loc>n+1){
        printf("\n\t\t Invalid Location !!\n");
        goto label ;
    }
    else{
        int count = 1;
        struct node *ptr, *newnode;
        ptr = head;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\t\tEnter the value of newnode : ");
        scanf("%d",&newnode->data);
        while(count != loc){
            ptr = ptr->Rnext;
            count ++;
        }
        newnode -> Lnext = ptr;
        newnode -> Rnext = ptr -> Rnext;
        ptr -> Rnext = newnode;
        ptr = ptr->Rnext;
        ptr->Lnext = newnode;
        n = n+1;
        printf("\n\t\tADDED SUCCESSFULLY.\n");
    }
}

void insertBfLoc_CDLL(){
    int loc;
    label :
    printf("\t\tEnter the location : ");
    scanf("%d",&loc);
    if(loc==2){
        insertBeg_CDLL();
    }
    else if(loc==n+1){
        insertEnd_CDLL();
    }
    else if(loc<2 || loc>n+2){
        printf("\n\t\t Invalid Location !!\n");
        goto label ;
    }
    else{
        int count = 1;
        struct node *ptr, *newnode;
        ptr = head;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\t\tEnter the value of newnode : ");
        scanf("%d",&newnode->data);
        while(count != loc-1){
            ptr = ptr->Rnext;
            count ++;
        }
        newnode -> Lnext = ptr;
        newnode -> Rnext = ptr -> Rnext;
        ptr -> Rnext = newnode;
        ptr = ptr->Rnext;
        ptr->Lnext = newnode;
        n = n+1;
        printf("\n\t\tADDED SUCCESSFULLY.\n");
    }
}

void insertAfLoc_CDLL(){
    int loc;
    label :
    printf("\t\tEnter the location : ");
    scanf("%d",&loc);
    if(loc==0){
        insertBeg_CDLL();
    }
    else if(loc==n){
        insertEnd_CDLL();
    }
    else if(loc<0 || loc>n){
        printf("\n\t\t Invalid Location !!\n");
        goto label ;
    }
    else{
        int count = 0;
        struct node *ptr, *newnode;
        ptr = head;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\t\tEnter the value of newnode : ");
        scanf("%d",&newnode->data);
        while(count != loc-1){
            ptr = ptr->Rnext;
            count ++;
        }
        newnode -> Lnext = ptr;
        newnode -> Rnext = ptr -> Rnext;
        ptr -> Rnext = newnode;
        ptr = ptr->Rnext;
        ptr->Lnext = newnode;
        n = n+1;
        printf("\n\t\tADDED SUCCESSFULLY.\n");
    }
}

void deletBeg_CDLL(){
    if(n==0){
        printf("\n\t\tNo element left in CDLL.\n");
    }
    else{
        struct node *ptr, *temp;
        ptr = temp = head;
        while(ptr -> Rnext != head){
            ptr = ptr ->Rnext;
        }
        ptr -> Rnext = temp -> Rnext;
        head = temp->Rnext;
        free(temp);
        n = n-1;
        printf("\n\t\tDELETED SUCCESSFULLY.\n");
    }
}

void deletEnd_CDLL(){
    if(n==0){
        printf("\n\t\tNo element is there in CDLL.\n");
    }
    else{
        struct node *ptr, *temp;
        ptr = temp = head;
        while(temp -> Rnext != head){
            ptr = temp;
            temp = temp -> Rnext;
        }
        ptr->Rnext = head;
        free(temp);
        n = n-1;
        printf("\n\t\tDELETED SUCCESSFULLY.\n");
    }
}

void deletMid_CDLL(){
    int count = 0;
    struct node *ptr, *temp, *temp2;
    temp = ptr = temp2 = head;

    while(count != n/2){
        ptr = temp;
        temp = temp->Rnext;
        count ++;
    }
    ptr->Rnext = temp->Rnext;
    temp2 = temp->Rnext;
    temp2->Lnext = ptr;
    free(temp);
    n = n-1;
    printf("\n\t\t DELETED SUCCESSFULLY.\n");
}

void deletLoc_CDLL(){
    int loc;
    label :
    printf("\t\tEnter the location : ");
    scanf("%d",&loc);
    if(loc == 1){
        deletBeg_CDLL();
    }
    else if(loc == n){
        deletEnd_CDLL();
    }
    else if(loc < 1 || loc > n){
        printf("\n\t\tInvalid Location.\n");
        goto label ; 
    }
    else{
        int count = 0;
        struct node *ptr, *temp, *temp2;
        temp = ptr = temp2 = head;
        while(count != loc){
            ptr = temp;
            temp = temp->Rnext;
            count ++;
        }
        ptr->Rnext = temp->Rnext;
        temp2 = temp->Rnext;
        temp2->Lnext = ptr;
        free(temp);
        n = n-1;
        printf("\n\t\tDELETED SUCCESSFULLY.\n");
    }
}

void deletBfLoc_CDLL(){
    int loc;
    label :
    printf("\n\tEnter the location : ");
    scanf("%d",&loc);
    if(loc==2){
        deletBeg_CDLL();
    }
    else if(loc == n+1){
        deletEnd_CDLL();
    }
    else if(loc < 2 || loc > n+1){
        printf("\n\t\t Invalid location !! Try agian...");
        goto label;
    }
    else{
        int count = 1;
        struct node *ptr, *ptr2;
        ptr2 = head;
        ptr = head->Rnext;
        while(count != loc-2){
            ptr2 = ptr;
            ptr = ptr->Rnext;
            count ++;
        }
        ptr2->Rnext = ptr->Rnext;
        free(ptr);
        ptr = ptr2->Rnext;
        ptr->Lnext = ptr2;
        n = n-1;
        printf("\n\t\t DELETED SUCCESSFULLY.\n");
    }
    
}

void deletAfLoc_CDLL(){
    int loc;
    label:
    printf("\n\t Enter the location : ");
    scanf("%d",&loc);
    if(loc==0){
        deletBeg_CDLL();
    }
    else if(loc == n-1){
        deletEnd_CDLL();
    }
    else if(loc < 0 || loc > n-1){
        printf("\n\t Invalid Location !! Try agian....");
        goto label;
    }
    else{
        int count = 0;
        struct node *ptr, *ptr2;
        ptr = head;
        while(count != loc){
            ptr2 = ptr;
            ptr = ptr->Rnext;
            count ++;
        }
        ptr2->Rnext = ptr->Rnext;
        free(ptr);
        ptr = ptr2->Rnext;
        ptr->Lnext = ptr2;
        n = n-1;
        printf("\n\t\t DELETED SUCCESSFULLY.\n");
    }
}

void deletKey_CDLL(){
    int s;
    printf("\n\t\tEnter value to be searched and removed : ");
    scanf("%d",&s);
    struct node *ptr, *ptr2, *ptr3;
    label:
    ptr = ptr2 = ptr3 = head;

    if(ptr->data==s){
        while(ptr->Rnext != head){
            ptr = ptr->Rnext;
        }
        ptr -> Rnext = ptr2->Rnext;
        head = head->Rnext;
        free(ptr2);
        n = n-1;
        printf("\n\t\tDELETED SUCCESSFULLY.\n");
    }
    ptr = ptr->Rnext;
    while(ptr->Rnext != head){
        if(ptr->data  == s){
            ptr3 = ptr->Rnext;
            ptr2->Rnext = ptr3;
            ptr3->Lnext = ptr2;
            n = n-1;
            printf("\n\t\tDELETED SUCCESSFULLY.\n");
            free(ptr);
            goto label;
        }
        ptr2 = ptr2->Rnext;
        ptr = ptr->Rnext;
    }
    if(ptr->data == s){
        deletEnd_CDLL();
    }
}

int main(){
    int x;
    create_CDLL();

    printf("\n01. To display the elements of CDLL.\n");
    printf("02. To search an element in the CDLL.\n");
    printf("03. To insert element at the begining of CDLL.\n");
    printf("04. To insert element at the end of the CDLL.\n");
    printf("05. To insert element at the mid of the CDLL.\n");
    printf("06. To insert element at a particular location.\n");
    printf("07. To insert element before a particular location.\n");
    printf("08. To insert element after a particular location.\n");
    printf("09. To delete the first element of the CDLL.\n");
    printf("10. To delete the last element of the CDLL.\n");
    printf("11. To delete the mid element of the CDLL.\n");
    printf("12. To delete the element from a particular location.\n");
    printf("13. To delete the element before a particular location.\n");
    printf("14. To delete the element after a particular location.\n");
    printf("15. To delete the element using key.\n");
    printf("16. To exit.\n");


    while(x){

        printf("\n\nWhat action would you like to perform : choose from options given above.\n");
        printf("Enter your choice : ");
        scanf("%d",&x);

        if(x==1){
            display_CDLL();
            continue;
        }
        else if(x==2){
            search_CDLL();
            continue;
        }
        else if(x==3){
            insertBeg_CDLL();
            continue;
        }
        else if(x==4){
            insertEnd_CDLL();
            continue;
        }
        else if(x==5){
            insertMid_CDLL();
            continue;
        }
        else if(x==6){
            insertLoc_CDLL();
            continue;
        }
        else if(x==7){
            insertBfLoc_CDLL();
            continue;
        }
        else if(x==8){
            insertAfLoc_CDLL();
            continue;
        }
        else if(x==9){
            deletBeg_CDLL();
            continue;
        }
        else if(x==10){
            deletEnd_CDLL();
            continue;
        }
        else if(x==11){
            deletMid_CDLL();
            continue;
        }
        else if(x==12){
            deletLoc_CDLL();
            continue;
        }
        else if(x==13){
            deletBfLoc_CDLL();
            continue;
        }
        else if(x==14){
            deletAfLoc_CDLL();
            continue;
        }
        else if(x==15){
            deletKey_CDLL();
            continue;
        }
        else{
            printf("\n\t\t_._._. THANK YOU ._._._");
            printf("\n\n.");
            break;
        }
    }
    return 0;
}
