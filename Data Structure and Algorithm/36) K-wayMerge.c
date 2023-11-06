/*

Hey Visitor ! This is my C program that performs K-way merge. It takes 'n' no of sorted or unsorted arrays
along with the their size from the user and return a final array - merging all the arrays in sorted (ascending) order.
Check out the overall concept of program at the bottom.

*/

#include <stdio.h>
#include<stdlib.h>

void merge(int arr[], int left[], int leftsize, int right[], int rightsize){
    int k=0,i=0,j=0;
    
    while(i<leftsize && j<rightsize){
        if(left[i]<=right[j])
            arr[k++]=left[i++];
        else
            arr[k++]=right[j++];
    }
    
    while(i<leftsize)
        arr[k++]=left[i++];
   
    while(j<rightsize)
        arr[k++]=right[j++];
}

void mergesort(int arr[], int n){
    if(n<=1)
        return;

    int mid = n/2;
    int left[mid];
    int right[n - mid];
    
    for(int i=0;i<mid;i++)
        left[i]=arr[i];

    for(int i=mid;i<n;i++)
        right[i-mid]=arr[i];

    mergesort(left, mid);
    mergesort(right, n - mid);
    
    merge(arr, left, mid, right, n - mid);
}

void mergearrays(int* arr[], int k, int size[]){
    int c=0;
    
    for(int i=0;i<k;i++)
        c +=size[i];
    
    int a[c];
    int n=0;
    for(int i=0;i<k;i++){
        for(int j=0;j<size[i];j++){
             a[n++] = arr[i][j];
        }
    }
    
    printf("\nMerged array: ");
    for(int i=0;i<c;i++){
        printf("%d ",a[i]);
    }
    
    mergesort(a, c);
    
    printf("\nSorted merged array: ");
    for(int i=0;i<c;i++){
        printf("%d ",a[i]);
    }
    printf("\n.");
}

int main(){
    int n,i,k,j=0;

    do{
        printf("\nEnter the number of the arrays: ");
        scanf("%d",&k);
        
        if(k<=2)
            printf("\nplease enter more than 2 arrays.....\n");
        else 
            break;
    }while(1);

    int* arr[k];
    int size[k];
    for(i=0;i<k;i++){
        printf("\nEnter the size of the %d array : ",i+1);
        scanf("%d",&size[i]);
        
        arr[i] = (int *)malloc(sizeof(int)*size[i]);
        
        for(j=0;j<size[i];j++){
            printf("Enter the %d value: ",j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    
    printf("\n-------------------------------------------\n\t\tResult : \n");
    for(i=0;i<k;i++){
        printf("\nArray %d data : ",i+1);
        for(j=0;j<size[i];j++){
            printf("%d ",arr[i][j]);
        }
    }
    printf("\n");
    mergearrays(arr, k, size);
    return 0;
}

/* 

PROGRAM FLOW AND DESIGN : 

1. First we take value of 'n' that is no of array that need to be merged.
2. Then, we take one by one their size and array data.
3. We keep size details of each array in separate array named 'size'.
4. Here in this program we have allocated memory dynamically because we can't create array
    in static manner as no of array to be merged is not fixed, and it depends on user.
    so, some time no of array can be 3, other time it can be 7 etc.
5. We have also taken care if passed array are not sorted then we sort them first.
6. Three functions used in program apart from main are : merge, mergesort and mergearrays.
7. 'mergesort' is the function that sort the passed arrays if any of them is not sorted.
8. 'mergesort' take help of 'merge' function to merge them as we are using Merge sort algorithm.
9. and the last 'mergearray' merge all the sorted arrays.
10. One more thing how we are dealing with size is we store first array size at first index in 'size' array
    size of second at seconde index and so on.
11. Hope overall idea is clear for logic understand prefer reading code.

*/