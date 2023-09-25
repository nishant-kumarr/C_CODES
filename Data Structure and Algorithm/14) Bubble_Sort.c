/*

Hello, Visitor! This is my code that facilitates the execution of a bubble sort algorithm on an array.
Feel free to use my codes to understand the core of C Data structure.

*/

#include<stdio.h>
int main(){
    int i,j,n,temp;
    printf("\nEnter no of element : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter no.s to be sorted : ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(i=1;i<n;i++){
        for(j=1;j<n;j++){
            if(arr[j-1]>arr[j]){
                temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("\nSorted elements =  ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}