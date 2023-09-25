/*

Hello, Visitor! This is my code that facilitates the execution of a selection sort algorithm on an array.
Feel free to use my codes to understand the core of C Data structure.

*/

#include<stdio.h>
int main(){
    int n,i,j,temp;
    printf("\nEnter the no of element : ");
    scanf("%d",&n);
    int arr[n];

    printf("\nEnter the array data : ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(i=0;i<n;i++){
        j=i;
        while(j>0 && arr[j-1] > arr[j]){
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }

    printf("\nSorted array = ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}