/* 

Greetings, Visitor! Below, you'll find my code that empowers you to execute a variety of operations on a Singly Linked List:
1. Create a Singly Linked List.
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
struct node *head, *ptr;
void *create_SLL();
void *display_SLL();
void *search_SLL();
void *insertBeg_SLL();
struct node *insertEnd_SLL(struct node *);
struct node *insertMid_SLL(struct node *);
struct node *insertLoc_SLL(struct node *);
struct node *insertBfLoc_SLL(struct node *);
struct node *insertAfLoc_SLL(struct node *);
void *deletBeg_SLL();
struct node *deletEnd_SLL(struct node *);
struct node *deletMid_SLL(struct node *);
struct node *deletLoc_SLL(struct node *);
struct node *deletBfLoc_SLL(struct node *);
struct node *deletAfLoc_SLL(struct node *);
void deletKey_SLL();


struct node{
    int data;
    struct node *next;
};

void *create_SLL(){
    int i;

    printf("\nEnter the no of element in SLL : ");
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
        printf("\tEnter node %d data : ",i);
        scanf("%d",&ptr->data);
    }
    ptr -> next = NULL;
}

void *display_SLL(){
    if(n==0){
        printf("\n\tZero Node in SLL.\n");
    }
    else{
        struct node *ptr;
        ptr = head;
        printf("\nElements of SLL are : ");
        while(ptr != NULL){
            printf("%d  ",ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void *search_SLL(){
    int s;
    printf("\tEnter the element to be searched : ");
    scanf("%d",&s);

    struct node *ptr;
    ptr = head;
    int count=0,flag=0;

    while(ptr != NULL){
        if(ptr->data == s){
            flag = 1;
            printf("\t\t%d is present at positon : %d\n",s,count+1);
        }
        count++;
        ptr = ptr-> next;
    }
    if(flag==0){
        printf("\t\tElement not presenet in the SLL.\n");
    }
}
   
void *insertBeg_SLL(){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the value to be added at the begining of SLL : ");
    scanf("%d",&newnode->data);
    newnode->next = head;
    head = newnode;
    n = n+1;
    printf("\n\tElement added at the beginning.\n");
}

struct node *insertEnd_SLL(struct node *head){
    struct node *newnode, *ptr;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the value to be added at the end of SLL : ");
    scanf("%d",&newnode->data);

    newnode -> next = NULL;
    ptr = head;

    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr -> next = newnode;
    n = n+1;
    printf("\n\tElement added at the end.\n");
    return(head);
}

struct node *insertMid_SLL(struct node *head){
    struct node *newnode, *ptr;
    newnode = (struct node *)malloc(sizeof(struct node));

    int loc,count = 1;
    printf("Enter value of the newnode : ");
    scanf("%d",&newnode->data);
    
    loc = n/2;

    ptr = head;
    while(count != loc){
        ptr = ptr->next;
        count ++;
    }
    newnode -> next = ptr -> next;
    ptr -> next = newnode;
    n = n+1;
    printf("\n\tElement added at the Mid. position.\n");
    return (head);
}

struct node *insertLoc_SLL(struct node *head){

    int loc;
    label : 
    printf("\nEnter the location where you want to insert : ");
    scanf("%d",&loc);

    if (loc==1){
        insertBeg_SLL();
    }
    if (loc>n+1){
        printf("\n\t\tInvalid location ! First insert at location %d\n",n+1);
        goto label;
    }
    if (loc != 1 && loc <=n+1){
        struct node *newnode, *ptr;
        newnode = (struct node *)malloc(sizeof(struct node));

        int count = 1;
        printf("Enter value of the newnode : ");
        scanf("%d",&newnode->data);

        ptr = head;
        while(count != loc-1){
        ptr = ptr->next;
        count ++;
    }
    newnode -> next = ptr -> next;
    ptr -> next = newnode;
    n = n+1;
    printf("\n\tElement added at the position %d\n",loc);
    return (head);
    }
}

struct node *insertBfLoc_SLL(struct node *head){
    int loc;
    label : 
    printf("\nEnter the location where you want to insert : ");
    scanf("%d",&loc);

    if (loc==1){
        insertBeg_SLL();
    }
    if (loc>n+2 || loc < 1){
        printf("\n\t\tInvalid location !\n");
        goto label;
    }
    if (loc != 1 && loc <=n+2){
        struct node *newnode, *ptr;
        newnode = (struct node *)malloc(sizeof(struct node));

        int count = 1;
        printf("Enter value of the newnode : ");
        scanf("%d",&newnode->data);

        ptr = head;
        while(count != loc-2){
        ptr = ptr->next;
        count ++;
    }
    newnode -> next = ptr -> next;
    ptr -> next = newnode;
    n = n+1;
    printf("\n\tElement added at the position %d\n",loc);
    return (head);
    }
}

struct node *insertAfLoc_SLL(struct node *head){
    int loc;
    label : 
    printf("\nEnter the location where you want to insert : ");
    scanf("%d",&loc);

    if (loc==0){
        insertBeg_SLL();
    }
    if (loc>n){
        printf("\n\t\tInvalid location ! First insert at location %d\n",n);
        goto label;
    }
    if (loc != 0 && loc <=n){
        struct node *newnode, *ptr;
        newnode = (struct node *)malloc(sizeof(struct node));

        int count = 1;
        printf("Enter value of the newnode : ");
        scanf("%d",&newnode->data);

        ptr = head;
        while(count != loc){
        ptr = ptr->next;
        count ++;
    }
    newnode -> next = ptr -> next;
    ptr -> next = newnode;
    n = n+1;
    printf("\n\tElement added at the position %d that is after %d\n",loc+1,loc);
    return (head);
    }
}

void *deletBeg_SLL(){
    struct node *ptr;
    ptr = head;
    head = head->next;
    free(ptr);
    printf("\n\tFirst element Deleted  successfully.\n");
    n = n-1;
}

struct node *deletEnd_SLL(struct node *head){
    struct node *temp, *ptr;
    ptr = head;
    while(ptr->next != NULL){
        temp = ptr;
        ptr = ptr->next;
    }
    temp -> next = NULL;
    free(ptr);
    printf("\n\tLast element Deleted successfully.\n");
    n = n-1;
    return (head);

}

struct node *deletMid_SLL(struct node *head){
    int loc, count = 1;
    struct node *temp, *ptr;

    loc = n/2;
    ptr = head;

    while(count != loc+1){
        temp = ptr;
        ptr = ptr-> next;
        count ++;
    }
    temp -> next = ptr -> next;
    free(ptr);
    printf("\n\t Mid element deleted successfully.\n");
    n = n-1;
    return(head);
}

struct node *deletLoc_SLL(struct node *head){
    int loc;
    label:
    printf("\nEnter the location : ");
    scanf("%d",&loc);
    if (loc ==1){
        deletBeg_SLL();
    }
    if(loc > n){
        printf("\n\t\tInvalid location ! There is only %d elements.\n",n);
        goto label;
    }
    if(loc <= n+1 && loc != 1){
        int count = 1;
        struct node *temp, *ptr;

        ptr = head;

        while(count != loc){
            temp = ptr;
            ptr = ptr-> next;
            count ++;
        }
        temp -> next = ptr -> next;
        free(ptr);
        printf("\n\t %d no. element deleted successfully.\n",loc);
        n = n-1;
        return(head);
    }
}

struct node *deletBfLoc_SLL(struct node *head){
    int loc;
    label:
    printf("\nEnter the location : ");
    scanf("%d",&loc);
    if (loc ==2){
        deletBeg_SLL();
    }
    if(loc > n+1 || loc < 2){
        printf("\n\t\tInvalid location ! Note that there are %d elements.\n",n);
        goto label;
    }
    if(loc <= n+1 && loc != 2){
        int count = 1;
        struct node *temp, *ptr;

        ptr = head;

        while(count != loc-1){
            temp = ptr;
            ptr = ptr-> next;
            count ++;
        }
        temp -> next = ptr -> next;
        free(ptr);
        printf("\n\t %d no. element deleted successfully.\n",loc);
        n = n-1;
        return(head);
    }
}

struct node *deletAfLoc_SLL(struct node *head){
    int loc;
    label:
    printf("\nEnter the location : ");
    scanf("%d",&loc);
    if (loc == 0){
        deletBeg_SLL();
    }
    if(loc >= n){
        printf("\n\t\tInvalid location ! There is only %d elements.\n",n);
        goto label;
    }
    if(loc < n && loc != 0){
        int count = 1;
        struct node *temp, *ptr;

        ptr = head;

        while(count != loc+1){
            temp = ptr;
            ptr = ptr-> next;
            count ++;
        }
        temp -> next = ptr -> next;
        free(ptr);
        printf("\n\tElement no %d deleted successfully.\n",loc+1);
        n = n-1;
        return(head);
    }
}

void deletKey_SLL(){
    int s;
    printf("\tEnter value to be searched and removed : ");
    scanf("%d",&s);
    struct node *ptr, *ptr2;
    label:
    ptr = ptr2 = head;
    if(ptr->data == s){
        head = head->next;
        free(ptr);
        n = n-1;
        printf("\n\tDeleted Successfully.\n");
        goto label;
    }
    ptr = ptr->next;
    while(ptr->next != NULL){
        if(ptr->data == s){
            ptr2->next = ptr->next;
            free(ptr);
            n = n-1;
            printf("\n\tDeleted Successfully.\n");
            goto label;
        }
        ptr2 = ptr2->next;
        ptr = ptr->next;
    }
    if(ptr->data == s){
        ptr2->next = NULL;
        free(ptr);
        n = n-1;
        printf("\n\tDeleted Successfully.\n");
    }
}

int main(){

    int x;
    create_SLL();

    printf("\n01. To dispalay SLL\n");
    printf("02. To search an element in SLL\n");
    printf("03. To insert a value to the beginning of SLL\n");
    printf("04. To insert a value to the end of SLL\n");
    printf("05. To insert a value at the mid of the SLL\n");
    printf("06. To insert a value at a particular location\n");
    printf("07. To insert a value before a particular location\n");
    printf("08. To insert a value at after particular location\n");
    printf("09. To delet the first element of SLL\n");
    printf("10. To delet the last element of SLL\n");
    printf("11. To delet the mid element of SLL\n");
    printf("12. To delet a value at a particlular location\n");
    printf("13. To delet before a value at a particlular location\n");
    printf("14. To delet after a value at a particlular location\n");
    printf("15. To delet using the value of node\n");
    printf("16. To exit\n");

    while(x){

        printf("\nWhat action would you like to perform : choose from options given above \n");
        printf("Enter your choice : ");
        scanf("%d",&x);

        if(x==1){
            display_SLL(head);
            continue;
        }
        else if(x==2){
            search_SLL();
            continue;
        }
        else if(x==3){
            insertBeg_SLL(head);
            continue;
        }
        else if(x==4){
            insertEnd_SLL(head);
            continue;
        }
        else if(x==5){
            insertMid_SLL(head);
            continue;
        }
        else if(x==6){
            insertLoc_SLL(head);
            continue;
        }
        else if(x==7){
            insertBfLoc_SLL(head);
            continue;
        }
        else if(x==8){
            insertAfLoc_SLL(head);
            continue;
        }
        else if(x==9){
            deletBeg_SLL(head);
            continue;
        }
        else if(x==10){
            deletEnd_SLL(head);
            continue;
        }
        else if(x==11){
            deletMid_SLL(head);
            continue;
        }
        else if(x==12){
            deletLoc_SLL(head);
            continue;
        }
        else if(x==13){
            deletBfLoc_SLL(head);
            continue;
        }
        else if(x==14){
            deletAfLoc_SLL(head);
            continue;
        }
        else if(x==15){
            deletKey_SLL();
            continue;
        }
        else{
            printf("\n_._._ THANK YOU _._._\n.");
            break;
        }
    }
    return 0;
}

