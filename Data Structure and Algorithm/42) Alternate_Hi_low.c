/*

    Hey Visitor ! This is program of mine that facilitates an interesting array arrangment as explained below : 
    Program requrirement : Given an integer array, rearrange it such that every second element becomes greater than
    its left and right elements. Assume no duplicate elements are present in the array.
    Check out the explanation at the bottom.

*/


#include <stdio.h>
 
void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
 
void rearrange_it(int arr[], int n){
    
    for (int i = 1; i < n; i += 2){

        if (arr[i - 1] > arr[i]) {
            swap(arr, i - 1, i);
        }
        if (i + 1 < n && arr[i + 1] > arr[i]) {
            swap(arr, i + 1, i);
        }

    }
}
 
int main(void){
    int i=1;
    while(i){
        if(i>1){
            printf("\nEnter 0 to Re-arrange another array, otherwise press 1 : ");
            int choice;
            scanf("%d",&choice);
            if(choice == 1){
                break;
            }
        }
        int n;
        i++;
        printf("\nEnter the no of element in the array : ");
        scanf("%d",&n);

        int arr[n];
        printf("Enter the array data : ");
        for(int i=0; i<n; i++){
            scanf("%d",&arr[i]);
        }
    
        rearrange_it(arr, n);
        
        printf("\nRe-arranged array is : ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        
    }

    printf("\n\n_");
    return 0;
}

/*

---- Explanation ----

1. In the main function we are taking the array size followed by array data.
2. Then, we pass the array along with its size to a function named 'arrange_it'
3. Inside that function we iterate the array from start to end and swap the values as :
    i) value at (i-1)th index is greater than i-th index or
    ii) value at (i+1)th index is greater than i-th and (i+1) is less than n.
4. In this program we have two functions other than main one is swap that swap value 
    of different index. and another as already said 'rearrange_it' rearrange the array.
5. That's it Hope it helps. Feel free to explore the code.

*/