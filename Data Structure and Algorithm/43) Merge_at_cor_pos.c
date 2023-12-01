/* 

    Hey visitor ! This is the program of mine that is based on merging of two arrays but with some twist.
    MERGE AT CORRECT POSITION ;
    Program requirement : You are being given array X and array Y along with their size m and n respectively.
    In array X there are some vacant indices that holds value zero you need to fill those indices with array Y
    data. Both the array are in sorted order, m >= n and no of vacant indices in array X is equal to no of 
    elements in array Y.
    In the output you need to print the merged array which will be sorted array. Explanation at the bottom.

*/


#include<stdio.h>

void merge(int X[], int Y[], int m, int n){
    int k = m + n + 1;
 
    // run if X[] or Y[] has elements left
    while (m >= 0 && n >= 0){
        // put the next greater element in the next free position in `X[]` from the end
        if (X[m] > Y[n]){
            X[k--] = X[m--];
        }
        else{
            X[k--] = Y[n--];
        }
    }
 
    // copy the remaining elements of `Y[]` (if any) to `X[]`
    while (n >= 0) {
        X[k--] = Y[n--];
    }
 
    // fill `Y[]` with all zeros
    for (int i = 0; i < n; i++) {
        Y[i] = 0;
    }
}

void rearrange(int X[], int Y[], int m, int n){
    if(m == 0){             // return if `X` is empty
        return;
    }

    int k = 0;              // moves non-empty elements of `X[]` at the beginning
    for (int i = 0; i < m; i++){
        if (X[i] != 0) {
            X[k++] = X[i];
        }
    }
 
    // merge `X[0 … k-1]` and `Y[0 … n-1]` into `X[0 … m-1]`
    merge(X, Y, k - 1, n - 1);
}

int main(){
    int m,n;
    restart:    // label
    printf("\nEnter the value of m (size of array x) and n (size of array y) : ");
    scanf("%d",&m);
    scanf("%d",&n);

    // check if array Y is bigger than X or not
    if(n > m){
        printf("value of m should be >= n");
        goto restart;
    }

    // Take array data
    int X[m], Y[n];
    printf("\nEnter array X data : ");
    for(int i=0; i<m; i++){
        scanf("%d",&X[i]);
    }
    printf("Enter array Y data : ");
    for(int j=0; j<n; j++){
        scanf("%d",&Y[j]);
    }

    // Merge the arrays
    rearrange(X,Y,m,n);

    printf("\nMerged array: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", X[i]);
    }
    printf("\n\n_");
    return 0;
}

/* 
----- Explanation -----

1. First, we take value of 'm' and 'n' that is the size of array-x and array-y followed by arrary data.
2. Then, we have two function that combinedly fulfill out program requirement.
3. First one is rearrange, using this function we move all non-zero data of array x to the front and all zeroes
   to the end.
4. Then, using merge function we merge sort the array x and array y. Point here to be noted is for array x we take 
   only that part which is non-zero.
5. Let's understand using example : Let m = 5 and n = 2 ; Array x = {1 0 4 5 0} and Array y = {1 9}. Note that as per 
    question x and y should be sorted in ascending order.
6. Then using rearrange function we will get x as {1 4 5 0 0} and then, we using merge function we will merge {1 4 5} from
    array x and array y.
7. So, our final array will be : Array x = {1 1 4 5 9}
8. Hope it helps, feel free to explore code above.


*/
