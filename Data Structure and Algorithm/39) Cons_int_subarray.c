/*

    Hey visitor ! This is the code of mine that facilitates a task on an array as explained below.
    Program requirement : Given an integer array, find the largest subarray formed by consecutive integers. 
    The subarray should contain all distinct values. For example, Input: { 2, 0, 2, 1, 4, 3, 1, 0 } 
    Output: The largest subarray is { 0, 2, 1, 4, 3 }.

    Approach explained at the bottom

*/


#include <stdio.h>

int largest_subarray(int a[], int n) {
    int index[100000] = {0};
    int length_of_subarray = 0, start = 0, end = 0;
    
    for (int i = 0, j = 0; i < n; i++) {
        j = (index[a[i]] > j) ? index[a[i]] : j;
        if (length_of_subarray < i - j + 1) {
            length_of_subarray = i - j + 1;
            start = j;
            end = i;
        }
        index[a[i]] = i + 1;
    }

    printf("\nLargest subarray without duplicates: ");
    for (int i = start; i <= end; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return length_of_subarray;
}

int main() {
    int n;
    printf("\nEnter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Length of the largest subarray: %d\n", largest_subarray(arr, n));
    printf("\n\n_");
    return 0;
}



/*
    ---- Explanation ----

1. First of all we take the array size and array data. 
2. Then, we use the function named 'largest_subarray' to print the subarray and get its size.
3. The function 'largest_subarray' works as :
    i) Here in this function, firstly we have an array named index with size 10k with all value initialised 
        to zero. Size of this array is taken based on an assumption that the size of original array (that user
        will give) will be in b/w 1 to 10k. This array is use to store the latest index of a particular no in the original
        array. Suppose the number_5 is at index 3 in original array then, in index array we will put 3 at the 
        index 5 of index array.
    ii) Then, we have three variables named 'start' - to store the starting index of sub-array. 'end' - to store the last index
        of sub-array. and 'length_of_subarray' - to store the current size of sub-array.
    iii) We are using two pointer variable while iterating through the array. one is 'i' for simple traversal and to point to
        the end of subarray and another is 'j' to point to the right most occurance of current (duplicate) element or the 
        start of subarray. 
        For example : suppose number 5 is present at index 2 and index 4 then, 'j' will point to right most that is 4th index. 
        This variable helps in finding the starting of sub-array that we are finding. As according to question we are trying
        to avoid duplicate so we will include the right-most element ignoring the left one to avoid duplicate in sub-array.
    iv) Now, whenever we find that the current sub-array size without duplicate is greater than the previous recorded subarray we 
        update the size to the greater one. Also we update the start and end of subarray accordingly.
    v) Also, we always keep on updating the index of last occurance of current number in index array.
    vi) After completing the traversal till the end we can print the subarray staring from index 'start' and ends with index
        'end' with size of 'length_of_subarray'.
4. Hope it helps, Feel free to explore code above for better understanding.


*/