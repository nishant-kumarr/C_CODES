/*

Hello, Visitor! Welcome to my code, designed to facilitate linear search operations on an array.
Feel free to explore these 'C Data structure' using my code!

*/

#include<stdio.h>

void Lsearch_WR(){
    int n,key,flag=0;
    printf("\nEnter the no of values : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter value to the array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\nEnter the key to search : ");
    scanf("%d",&key);
    for(int j=0;j<n;j++){
        if(a[j]==key){
            flag = 1;
            printf("%d found at %d",key,j+1);
        }
    }
    if(flag == 0){
        printf("\tKey not found");
    }
}


void LsearchR(int index){
    int n,key,flag=0;
    printf("\nEnter the no of values : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter value to the array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\nEnter the key to search : ");
    scanf("%d",&key);
    if(index > n-1){
        printf("\tElement not found\n");
    }
    else if(a[index]==key){
        printf("%d found at loc %d ",key,index+1);
    }
    else{
        LsearchR(index+1);
    }

}

int main(){
    printf("\n1. To search without recursion");
    printf("\n2. To search using recursion");

    int x;
    while(1){
        printf("\n\tEnter your choice : ");
        scanf("%d",&x);

        if(x==1){
            Lsearch_WR();
            continue;
        }
        else if(x==2){
            int index;
            LsearchR(index = 0);
            continue;
        }
        else{
            printf("\n_-_-_- THANK YOU -_-_-_");
        }
    } 
}