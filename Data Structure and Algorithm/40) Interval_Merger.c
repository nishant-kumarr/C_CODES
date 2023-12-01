/*

    Hey Visitor ! This is code of mine that fulfills the below requirement
    Program Requirement : You have to take certain no of intervals from user and you need to merge the overlapping
    intervals. Suppose you have been given {{1,5} {2,3} {4,6} {7,10}} then you need to return the merged interval {{1,6} {7,10}}

    Explain : Lets understand overlapping - Take this way interval {1,5} means you draw a line from coordinate 1 to 5 on x-axis
    similarly {2, 3} means you draw a line from 2 to 3, interval {4, 6} means you draw a line from 4 to 6 and {7 10} means you 
    draw line from 7 to 10 on x axis. One more thing you are drawing line exactly over the x-axis that means lets it coincide with
    x-axis then, there is a line from 1 to 5 and 2 to 3 conciding these lines you will get continuous line from 1 to 5 also there is 
    line from 4 to 6 so ultimately you continous line from 1 to 6 and at last there is line from 7 to 10. but since there is not line
    connecting between 6 to 7 so, we don't get a continuous line from 1 to 7 so we can't merge them and hence our final intervals after 
    merging will be {1,6} {7,10}.

    Do not forget to check program explanation given at the bottom

*/


#include<stdio.h>
#include<stdlib.h>

struct interval{
    int start;
    int end;
};

// Function that check for overlapping for two intervals
int intervals_comparator(const void *a, const void *b){
    return((struct interval *)a)->start - ((struct interval *)b)->start;
}

// Main function that merge overlapping intervals
void merger(struct interval arr[], int n){
    // sorting the intervals using quick sort
    qsort(arr,n,sizeof(struct interval),intervals_comparator);


    // Printing the intervals after sorting
    printf("\nIntervals after sorting are : {");
    for(int i=0; i<n; i++){
        printf("{%d, %d}",arr[i].start, arr[i].end);
        if(i<n-1){
            printf(", ");
        }
    }
    printf("}\n");


    // Traversing and merging the overlapping intervals
    int index = 0; // using two index one from 0 other variable-i of the loop from 1 to compare intervals

    for(int i=1;i<n;i++){
        if(arr[index].end >= arr[i].start){
            arr[index].end = (arr[index].end > arr[i].end) ? arr[index].end : arr[i].end;
        }
        else{
            index ++;
            arr[index] = arr[i];
        }
    }

    // Printing the intervals after merging
    printf("Intervals after merging are : {");
    for(int i=0; i<=index; i++){
        printf("{%d, %d}",arr[i].start, arr[i].end);
        if(i<index){
            printf(", ");
        }
    }
    printf("}\n");
}

int main(){
    int n;
    printf("\nEnter the no of intervals : ");
    scanf("%d",&n);
    
    // Allocate memory for intervals and give address to the pointer of type structure 
    struct interval *arr = (struct interval *)malloc(n*sizeof(struct interval));

    // Taking the intervals value
    for(int i=0; i<n; i++){
        printf("Enter interval %d start and end value : ",i+1);
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // Merge the intervals
    merger(arr,n);
    free(arr);
    printf("\n\n_");
    return 0;

}


/*

--- Program approach ---

1. We are using structure to store a interval
2. On the start of program we take the no of intervals from the user
3. Then, we dynamically allocate the memory for those no of intervals
4. Then, we take the intervals data from the user 
5. Then, we sort them in ascending order that will make our merging easier
6. For merging we take two varible pointer adjacent to each other as i start from index 0 and j starts from index 1
6. Then finally, we merge them as : 
    i) if the end of (i)th interval is greater than or equal to the start of j-th interval then replace the i-th 
    interval end with the one which is maximum in between {i-th interval end} and {j-th interval end}
    ~ Note that we are denoting the interval 1st value as 'First' and 2nd value as 'End'. Just like if interval is {1,5} then,
    line will start from coordinate-1 and will end at coordinate-2

    ii) else if above condition do not satisfy simply increment the 'i' and 'j' and replace i-th interval value with 
    j-th interval value.
    
    iii) Iterate it until 'j' satisfy the condition j<n
7. In the last we get the merged interval that now we can print it
8. Hope it helps, To make it more clear check how this program is executing using some problem as given below.
9. Test Cases to play with : 
    (i) Un-merged intervals : {{1,5} {2,3} {4,6} {7,10}} -> after merging {{1,6} {7,10}}
    (ii) Un-merged intervals : {{1,5} {2,3} {4,6} {7,8} {8,10} {12,15}} -> after merging {{1,6} {7,10} {12 15}}
    (iii) Un-merged intervals : {{1,8} {2,6} {4,9} {7,12} {10,15}} -> after merging {1,15}

10 Time complexity - O(nlogn) and space complexity - O(1)

*/