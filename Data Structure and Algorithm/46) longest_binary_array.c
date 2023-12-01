/*

    Hey Visitor! This is a code that facilitates the below program requirement.
    Program requirement : Given a binary array, find the maximum sequence of continuous 1’s that can 
    be formed by replacing at most k zeros by ones. For example : If Input array A[] = {1 1 0 1 1 0 1 1 1 1 0 0}
    and K = 2 then, the length of the longest sequence of 1's is 10 (from index 0 to 9).
    You have been given, n - array size followed by array data and K - no of inversion allowed that is no of zeroes
    that can be converted to one.
    Do not forget to check out the explanation at the bottom.

*/

#include<stdio.h>

void finder_func(int arr[], int n, int k){
    int left = 0;     // points to current sub_array starting point
    int count = 0;    // stores the total no of zeroes in current sub_array
    int sub_array = 0;   // stores maximum no of continuous 1's found so far including 'k' zeroes
    int leftIndex = 0;    // stores the left index of longest sub_array found so far

    for (int right = 0; right < n; right++){
        if (arr[right] == 0){ // if you incounter zero update the count.
            count++;
        }

        while (count > k) {
            if (arr[left] == 0){ // if no of zeroes increases the K drop it from left side
                count--;
            }
            left++;
        }

        if (right - left + 1 > sub_array){  // Update the sub_array index as per longest found so far
            sub_array = right - left + 1;
            leftIndex = left;
        }
    }
    
    // print the result
    printf("\nThe longest possible sub_array is from index %d to %d of size %d",leftIndex, (leftIndex + sub_array -1), sub_array);
    printf("\n\n_");
}

int main(){
    int n;
    printf("\nEnter the size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array data : ");
    for(int i=0 ; i<n; i++){
        scanf("%d",&arr[i]);
    }
    int k;
    printf("Enter the no of zeroes allowed to invert : ");
    scanf("%d",&k);
    finder_func(arr,n,k);
    return 0;
}

/* 
    ---- Explanation ----

We can solve this problem by using the sliding 'sub_array' technique. The idea is to maintain a 'sub_array' containing 
at most k zeros at any point. Add elements to the 'sub_array' from the right until it becomes unstable. The 'sub_array'
becomes unstable if the total number of zeros in it becomes more than k. If the 'sub_array' becomes unstable, remove 
elements from its left till it becomes stable again (by removing leftmost zero). If the 'sub_array' is stable and the
current 'sub_array' length is more than the maximum 'sub_array' found so far, set the maximum 'sub_array' size to the 
current 'sub_array' size.

1. Firstly, we take the array size, array data and the value of K from the user.
2. Then, we use finder_func to find the longest sequence of 1's with at most K zeroes in it
    (we assume that we have inverted that zero to one).
3. The finder_func works as : 
    i) We traverse the array and keep on building subarray from left to right whenever we encounter zero,
        we increment the count.
    ii) When the count that means the no of zero becomes more than K we use while loop and traverse from left till
        we encounter leftmost zero and we keep on dropping elements from left of sub_array that means now sub_array starts after that
        dropped zero. This way we try with all possible subarray. That is which zero to invert to get largest subarray.
    iii) and when we are not dropping any element from left in that case we have the largest till that point. but when count
        become more than K we drop from left and we form subarray with another zero then, in that case we need to check
        which subarray was bigger so, we compare and update the 'sub_array' and its indices.
4. In the last we print the sub_array size and the indices. Hope it helps, explore code and draw on paper to understand better.

*/