/*

Hey visitor ! This is my code that facilitates a program that is explained below : 

Program requirement : You are given with array of n distinct intergers along with size and another integer X. 
Write a program to find whether there exist two integers whose sum is X or not, find all possible pairs available.

 !!!  CONCEPT EXPLAINED AT THE BOTTOM  !!!

*/



#include <stdio.h>

void merge(int arr[], int left[], int leftSize, int right[], int rightSize){ // function to merge two sorted parts.
    int i = 0, j = 0, k = 0;
    
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    
    while (i < leftSize){
        arr[k++] = left[i++];
    }
    while (j < rightSize){
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int size){    // Function that performs sorting.
    if (size <= 1)
        return;
    
    int mid = size / 2;
    int left[mid];
    int right[size - mid];
    
    for (int i = 0; i < mid; i++){
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++){
        right[i - mid] = arr[i];
    }
    mergeSort(left, mid);       // recursively calling for smaller halves after breaking into smaller sub-array.
    mergeSort(right, size - mid);
    
    merge(arr, left, mid, right, size - mid);   // after that merging those chunks.
}

int main() {            // main body.
    int n;
    printf("\nEnter no of elements : ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the array data : ");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, n);          // Sorting Data.
    
    int lo = 0, hi = n-1,sum = 0,flag = 0;

    printf("Enter the sum you are searching for : ");
    scanf("%d",&sum);
    printf("\n");
    
    while(lo<hi){                   // while loop for finding pairs
        if(arr[lo] + arr[hi] == sum){
            printf("%d %d are the numbers whose sum is %d\n",arr[lo],arr[hi],sum);
            flag = 1;
            lo++;
        }
        else if(arr[lo]+arr[hi] > sum){
            hi--;
        }
        else{
            lo++;
        }
    }
    if(flag == 0){
        printf("Pair not found ");   
    }
    return 0;
}


/* 

CONCEPT : 

1. Take the array size, array data and Sum that to be searched.

2. Perform merge sort.

3. Check for Pairs (two numbers only) as stated below : 

    i) Take two variable 'low' at starting of array & another 'high' at end.
    
    ii) Iterate the while loop until low < high.
    
    iii) Inside that while loop if arr[low] + arr[high] equals sum, print it and 
    	 change flag = 1 and increase low to avoid infinite loop with that pair, or 
    	 you can decrease the high, both way will be good to go.
    	 
    iv) else if arr[low] + arr[high] is greater than sum, since array is sorted so, 
        decrease the 'high' to try with a lower value.
        
    v) else, definetley the arr[low] + arr[high] is lower, so, increase the 'low' to 
       try with higher value, as the array is sorted.
       
4. Now, if the while loop iterated and didn't found any pair, that means flag will be 
   zero as initialised So, write a statement here to print "Pair not found".
   
5. That's it. and Time complexity : O(nlogn)

*/
