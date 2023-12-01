/*
    Hey visitor ! This is code of mine that calculate the maximum contiguous sum in an array in O(n) time complexity.
    For example : 
    If the array given is : [-2, -3, 4, -1, -2, 1, 5, -3] the maximum contiguous sum is 7. From sub-array [4, -1, -2, 1, 5].
    Do not forget to check the approach provided at the bottom
*/

#include<stdio.h>
#include<math.h>
int find_max_contiguous_sum(int array[],int n){
    int best = 0, sum = 0;
    int beg = 0, start = 0, end = 0;
    for (int k = 0; k < n; k++) {
        sum = sum + array[k];
        if(sum < array[k]){
            sum = array[k];
            beg = k;
        }
        if(best < sum){
            best = sum;
            start = beg;
            end = k;
        }
    }
    printf("\nSub-array with maximum continuous sum is {");
    for(int i=start; i<=end; i++){
        printf("%d",array[i]);
        if(i < end){
            printf(", ");
        }
    }
    printf("} \nwith maximum contiguous sum %d",best);
}

int main(){
    int n;
    printf("\nEnter the size of the array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array data : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    find_max_contiguous_sum(arr,n);
    printf("\n\n_");
    return 0;
}

/*
-- CONCEPT --

1. Firstly, we take array size and the array data. 
2. then, we find the maximum contiguous sum as : 

    i) Take two variable sum and best and initialise with zero.
    ii) Take three more variable beg - to mark the start of positive sum, 'start' to mark the start and 'end' to mark
        the end of sub-array that we are searching for as we will use these index to print it later.
    iii) Sum represent sum of first i value of array.
    iv) Best represent the maximum value ever got till the current traversal.
    v) Now, iterate through the array and at each index calculate sum = max(arr[i], sum+arr[i])
        and Best = max(sum,Best) as we are trying to figure out maximum possible contiguous sum.
    vi) At the end, value of Best will be our answer.

3. Hope, its clear, for more clarity on this try finding how value of 'sum' and 'best' is changing at each 
    index by taking an array for calculating. We had taken one example above while explaining question, try with that.

4. Time complexity - O(n)
*/