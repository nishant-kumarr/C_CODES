/*

    Hey visitor ! This is my code that facilitates a code requirement on a 1D array as explained below.
    Program requirement : Given an integer array, move all zeros present in it to the end. The solution should maintain
    the relative order of items in the array and should not use constant space. For example : if the input array is 
    {6 0 8 2 3 0 4 0 1} then, output should be {6 8 2 3 4 1 0 0 0}.
    Code explanation at the bottom.

*/




#include<stdio.h>
int main(){
    int n;      // Take array size
    printf("\nEnter the array size : ");
    scanf("%d",&n);
    
    int arr[n];     // Take array data
    printf("Enter the array data: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int k = 0;      // Rearrang the array
    for(int i=0; i<n; i++){     // Put all non-zero to the starting of array
        if(arr[i] != 0){
            arr[k++] = arr[i];
        }
    }
    for(int j = k; j<n; j++){   // Put all zero to the end of array 
        arr[j] = 0;
    }

    printf("\nArray after transformation : ");      // print the array
    for(int p=0; p<n; p++){
        printf("%d ",arr[p]);
    }
    printf("\n\n_");
    return 0;
}


/*

---- Explanation ----

1. Take the array size and array data.
2. Traverse through the array and whenever you find a non-zero element move it to front using a second pointer.
3. After traversing to the end of element. From the point where you have stored last non-zero number 
    to the end of array put zero.
4. That's it now the array is rearranged. Just print it.

*/