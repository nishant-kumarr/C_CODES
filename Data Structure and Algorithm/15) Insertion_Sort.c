/*

Hello, Visitor! This is my code that facilitates the execution of a Insertion sort algorithm on an array.
Feel free to use my codes to understand the core of C Data structure.

*/

#include<stdio.h>
int main(){
    int i,j,n,temp;
    printf("\nEnter the no of element : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements to be sorted : ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(i=0;i<n;i++){
        for(j=0;j<n-i;j++){
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