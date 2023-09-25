/* 

Greetings, Visitor! Below, you'll find my code that empowers you to execute a variety of operations on a Circularly Linked List:
1. Create a Circularly Linked List.
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
void create_CLL();
void display_CLL();
void search_CLL();
void insertBeg_CLL();
void insertEnd_CLL();
void insertMid_CLL();
void insertLoc_CLL();
void insertBfLoc_CLL();
void insertAfLoc_CLL();
void deletBeg_CLL();
void deletEnd_CLL();
void deletMid_CLL();
void deletLoc_CLL();
void deletBfLoc_CLL();
void deletAfLoc_CLL();
void deletKey_CLL();


struct node{
    int data;
    struct node *next;
};

void create_CLL(){
    struct node *ptr;
    int i;
    printf("\nEnter no of element in CLL : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        if(i==1){
            head = (struct node *)malloc(sizeof(struct node));
            ptr = head;
        }
        else{
            ptr -> next = (struct node *)malloc(sizeof(struct node));
            ptr = ptr -> next;
        }
        printf("\t\tEnter value of node %d : ",i);
        scanf("%d",&ptr->data);
    }
    ptr->next = head;
}

void display_CLL(){
    if(n==0){
        printf("\n\t\t No element in CLL.\n");
    }
    else{
        struct node *ptr;
        ptr = head;
        printf("\n\t\tElements of CLL are : ");
        printf("%d  ",ptr->data);
        ptr = ptr->next;
        while(ptr != head){
            printf("%d  ",ptr->data);
            ptr = ptr->next;
        }
    } 
}

void search_CLL(){
    struct node *ptr;
    int s,count =1, flag =0;
    printf("\t\tEnter the value to be searched  : ");
    scanf("%d",&s);
    ptr = head;
    while(ptr->next != head){
        if(ptr->data == s){
            printf("\t\t\t%d found at position %d\n",s,count);
            flag = 1;
        }
        ptr = ptr->next;
        count++;
    }
    if(ptr->data == s){
        printf("\t\t\t%d found at position %d\n",s,count);
        flag = 1;
    }
    if(flag == 0){
        printf("\t\t\t%d is not present in CLL.\n",s);
    }
}

void insertBeg_CLL(){
    struct node *ptr, *newnode;
    ptr = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value of node to be added : ");
    scanf("%d",&newnode->data);
    newnode -> next = head;
    while(ptr->next != head){
        ptr = ptr->next;
    }
    head = newnode;
    ptr->next = head;
    n = n+1;
    printf("\n\t\t ADDED SUCCESSFULLY.\n");
}

void insertEnd_CLL(){
    struct node *ptr, *newnode;
    ptr = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\t\tEnter value of node to be added : ");
    scanf("%d",&newnode->data);
    newnode->next = head;
    while(ptr->next != head){
        ptr = ptr->next;
    }
    ptr->next = newnode;
    n = n+1;
    printf("\n\t\t ADDED SUCCESSFULLY.\n");
}

void insertMid_CLL(){
    struct node *ptr, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter value of node to be added : ");
    scanf("%d",&newnode->data);
    ptr = head;
    int loc = n/2, count = 1;
    while(count != loc){
        ptr = ptr -> next;
        count ++;
    }
    newnode->next = ptr->next;
    ptr->next = newnode;
    n = n+1;
    printf("\n\t\t ADDED SUCCESSFULLY.\n");
}

void insertBfLoc_CLL(){
    int loc;
    label : 
    printf("\n\t\tEnter the location : ");
    scanf("%d",&loc);
    if (loc==2){
        insertBeg_CLL();
    }
    else if (loc>n+2 || loc < 2){
        printf("\n\t\tInvalid location !");
        goto label;
    }
    else if(loc == n+2){
        insertEnd_CLL();
    }
    else if (loc != 2 && loc <n+2){
        int count = 1;
        struct node *ptr, *newnode ;
        ptr = head;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter value of node to be added : ");
        scanf("%d",&newnode->data);
        while(count != loc-2){
            ptr = ptr->next;
            count ++;
        }
        newnode->next = ptr->next;
        ptr->next = newnode;
        n = n+1;
        printf("\n\t\t ADDED SUCCESSFULLY.\n");
    }
}

void insertAfLoc_CLL(){
    int loc;
    label : 
    printf("\n\t\tEnter the location : ");
    scanf("%d",&loc);
    if (loc==0){
        insertBeg_CLL();
    }
    else if (loc>n || loc < 0){
        printf("\n\t\tInvalid location !");
        goto label;
    }
    else if(loc == n){
        insertEnd_CLL();
    }
    else if (loc !=  0&& loc <n){
        int count = 1;
        struct node *ptr, *newnode ;
        ptr = head;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter value of node to be added : ");
        scanf("%d",&newnode->data);
        while(count != loc){
            ptr = ptr->next;
            count ++;
        }
        newnode->next = ptr->next;
        ptr->next = newnode;
        n = n+1;
        printf("\n\t\t ADDED SUCCESSFULLY.\n");
    }
}

void insertLoc_CLL(){
    int loc;
    label : 
    printf("Enter the location : ");
    scanf("%d",&loc);
    if (loc==1){
        insertBeg_CLL();
    }
    else if (loc>n+1 || loc < 1){
        printf("\n\t\tInvalid location !");
        goto label;
    }
    else if(loc == n+1){
        insertEnd_CLL();
    }
    else if (loc != 1 && loc <n+1){
        int count = 1;
        struct node *ptr, *newnode ;
        ptr = head;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter value of node to be added : ");
        scanf("%d",&newnode->data);
        while(count != loc-1){
            ptr = ptr->next;
            count ++;
        }
        newnode->next = ptr->next;
        ptr->next = newnode;
        n = n+1;
        printf("\n\t\t ADDED SUCCESSFULLY.\n");
    }
}

void deletBeg_CLL(){
    struct node *ptr, *temp;
    ptr = head;
    temp = head;
    while(ptr->next != head){
        ptr = ptr->next;
    }
    head = head->next;
    ptr->next = head;
    free(temp);
    n = n-1;
    printf("\n\t\t DELETED SUCCESSFULLY.\n");
}

void deletEnd_CLL(){
    if(n==0){
        printf("\n\t\t NO ELEMENT LEFT TO DELETE !!\n");
    }
    else{
        struct node *ptr,*temp;
        temp = head;
        ptr = head;
        while(temp->next != head){
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = head;
        free(temp);
        n = n-1;
        printf("\n\t\t DELETED SUCCESSFULLY.\n");
    }
}

void deletMid_CLL(){
    int count = 0, loc = n/2;
    if(n==0){
        printf("\n\t\t NO ELEMENT LEFT.\n");
    }
    else{
        int count = 0, loc = n/2;
        struct node *ptr, *temp;
        ptr = head;
        temp = head;
        while(count != loc){
            ptr = temp;
            temp = temp->next;
            count ++;
        }
        ptr->next = temp->next;
        free(temp);
        n = n-1;
        printf("\n\t\t DELETED SUCCESSFULLY.\n");
    }
}

void deletLoc_CLL(){
    int loc;
    printf("\t\t Enter the location : ");
    scanf("%d",&loc);
    if(n=0){
        printf("\n\t\t NO ELEMENT LEFT.\n");
    }
    else if(loc==1){
        deletBeg_CLL();
    }
    else if(loc == n){
        deletEnd_CLL();
    }
    else{
        int count=1;
        struct node *ptr, *temp;
        temp = head;
        ptr = head;
        while(count != loc){
            ptr = temp;
            temp = temp->next;
            count ++;
        }
        ptr->next = temp->next;
        free(temp);
        n = n-1;
        printf("\n\t\t DELETED SUCCESSFULLY.\n");
    }
}

void deletBfLoc_CLL(){
    int loc;
    label :
    printf("\n\tEnter the location : ");
    scanf("%d",&loc);
    if(loc==2){
        deletBeg_CLL();
    }
    else if(loc == n+1){
        deletEnd_CLL();
    }
    else if(loc < 2 || loc > n+1){
        printf("\n\t\t Invalid location !! Try agian...");
        goto label;
    }
    else{
        int count = 1;
        struct node *ptr, *ptr2;
        ptr2 = head;
        ptr = head->next;
        while(count != loc-2){
            ptr2 = ptr;
            ptr = ptr->next;
            count ++;
        }
        ptr2->next = ptr->next;
        free(ptr);
        ptr = ptr2->next;
        n = n-1;
        printf("\n\t\t DELETED SUCCESSFULLY.\n");
    }
}

void deletAfLoc_CLL(){
    int loc;
    label:
    printf("\n\tEnter the location : ");
    scanf("%d",&loc);
    if(loc==0){
        deletBeg_CLL();
    }
    else if(loc == n-1){
        deletEnd_CLL();
    }
    else if(loc < 0 || loc > n-1){
        printf("\n\t\t Invalid Location !! Try agian....");
        goto label;
    }
    else{
        int count = 1;
        struct node *ptr, *ptr2;
        ptr2 = head;
        ptr = head->next;
        while(count != loc){
            ptr2 = ptr;
            ptr = ptr->next;
            count ++;
        }
        ptr2->next = ptr->next;
        free(ptr);
        ptr = ptr2->next;
        n = n-1;
        printf("\n\t\t DELETED SUCCESSFULLY.\n");
    }
}

void deletKey_CLL(){
   int s;
   printf("\n\t\tEnter data to be searched and deleted : ");
   scanf("%d",&s);
   struct  node *ptr, *ptr2;
   label :
   ptr = ptr2 = head;
   if(ptr->data == s){
        while(ptr->next != head){
            ptr = ptr->next;
        }
        ptr->next = ptr2->next;
        head = ptr2->next;
        free(ptr2);
        n = n-1;
        printf("\n\t\tDELETED SUCCESSFULLY.\n");
        ptr2 = head;
        goto label;
   }
   ptr = ptr->next;
   while(ptr->next != head){
        if(ptr->data == s){
            ptr2->next = ptr->next;
            free(ptr);
            ptr = ptr2->next;
            n = n-1;
            printf("\n\t\tDELETED SUCCESSFULLY.\n");
            goto label;
        }
        ptr = ptr->next;
        ptr2 = ptr2->next;
   }
   if(ptr->data == s){
        deletEnd_CLL();
   }
}

int main(){
    int x;
    create_CLL();

    printf("\n01. To dispalay the elements of CLL\n");
    printf("02. To search an element in CLL\n");
    printf("03. To insert an element at the beginning.\n");
    printf("04. To insert an element at the end.\n");
    printf("05. To insert an element at the mid position.\n");
    printf("06. To insert an element at a particular location.\n");
    printf("07. To insert an element before a particular location.\n");
    printf("08. To insert an element after a particular location.\n");
    printf("09. To delete the first element of the CLL.\n");
    printf("10. To delete the last element of the CLL.\n");
    printf("11. To delete the mid element of the CLL.\n");
    printf("12. To delete an element from a particular location.\n");
    printf("13. To delete the element before a particular location.\n");
    printf("14. To delete the element after a particular location.\n");
    printf("15. To delete element using key.\n");
    printf("16. To exit.\n");
    
    while(x){

        printf("\nWhat action would you like to perform : choose from options given above \n");
        printf("Enter your choice : ");
        scanf("%d",&x);

        if(x==1){
            display_CLL(head);
            continue;
        }
        else if(x==2){
            search_CLL();
            continue;
        }
        else if(x==3){
            insertBeg_CLL();
            continue;
        }
        else if(x==4){
            insertEnd_CLL();
            continue;
        }
        else if(x==5){
            insertMid_CLL();
            continue;
        }
        else if(x==6){
            insertLoc_CLL();
            continue;
        }
        else if(x==7){
            insertBfLoc_CLL();
            continue;
        }
        else if(x==8){
            insertAfLoc_CLL();
            continue;
        }
        else if(x==9){
            deletBeg_CLL();
            continue;
        }
        else if(x==10){
            deletEnd_CLL();
            continue;
        }
        else if(x==11){
            deletMid_CLL();
            continue;
        }
        else if(x==12){
            deletLoc_CLL();
            continue;
        }
        else if(x==13){
            deletBfLoc_CLL();
            continue;
        }
        else if(x==14){
            deletAfLoc_CLL();
            continue;
        }
        else if(x==15){
            deletKey_CLL();
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


