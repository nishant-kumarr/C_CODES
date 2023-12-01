/*

    Hey visitor ! This is my code in C language that solve the coin change problem as explained below.
    Statement : You are being given certain number of coin denomination and a value, you  need to figure
    out in how many ways we can achieve that value using coin different coin combination.
    For Example : Suppose you are shopkeeper and you have coins of rupee 1, rupee 2 and rupee 3 and you need 
    to return rupee 4 to customer. then, you will have 4 differnt coin combinations to return rupee 4 and they are 
    {1,1,1,1} {2,2} {1,3} {1,1,2}. Your program need to find that no of combination. In this case it is 4.

    Do not forget to check the code approach and explanation at the bottom.

*/

#include<stdio.h>

int find_no_of_ways(int arr[], int n, int value){
    int matrix[n][value+1];
    // building the matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<=value;j++){
            if(j==0){
                matrix[i][j] = 1;
            }
            else if(i==0){
                if(j%arr[0]==0){
                    matrix[i][j] = 1;
                }
                else{
                    matrix[i][j] = 0;
                }
            }
            else if(j<arr[i]){
                matrix[i][j] = matrix[i-1][j];
            }
            else{
                matrix[i][j] = (matrix[i-1][j] + matrix[i][j-arr[i]]);
            }
        }
    }
    printf("\nPrinting the matrix : \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<=value;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    return matrix[n-1][value];
}


int main(){
    int n;
    printf("\nEnter the no of types of demonimations : ");
    scanf("%d",&n);
    int deno[n];
    printf("Enter the different denominations : ");
    for(int i=0;i<n;i++){
        scanf("%d",&deno[i]);
    }
    int value;
    printf("Enter the value to be returned : ");
    scanf("%d",&value);

    int res;
    res = find_no_of_ways(deno,n,value);
    printf("\nNo of ways value can generated using availabe denomination is : %d\n\n",res);
    return 0;
}


/*

There are differnt approach to solve this problem such as using Recursive approach, Greedy algorithm, 
Brute-force, backtracing algorithm etc. but these methods can not be always efficient for large sum and 
denominations. so, here we have one more way called Dynamic Programming and we have used this only in this program.

1. First we take inputs from the user like - no of denominations and then the denominations.
2. then, we take the value that need to find for.
3. Then, we create a 2D matrix with size [no of deominations][zero to sum]
4. Suppose denominations are {1, 2, 3} and sum is 4 then size will be 3x5. 5 because 0 to 4 counts 5.
5. Here, in this matrix rows represent value from 0 to desired value. and column represent different denominations
                                                                                                in ascending order.
6. Then we fill the matrix as : 
    i) Firstly we will be filling first column and first row then, we will fill further using their help.
    ii) For the first column we have to find sum zero with different denominations and that can be done with only one
    way so first column contains always 1. As for rupee zero someone can have always one way that is no requirement of any 
    coin. so, we are done with first column. 
    iii) Now, for first row we will be checking for 'rupee zero to value' (that we are finding) if that can be achieved by 
    that coin we we will put 1 else we will put zero to the index [coin][value]. For example if we have coins 2,3,4 and since
    we are at row 1 so, we are dealing with coin of rupee 1 and suppose value is 4 then, for value 0 it will be always one as 
    explained above and for value 1 we can't make using 2 rupee coin so, we will put zero and for 2 rupee coin we can make using 
    two rupee coin as one 2 rupee coin so we will put 1 and for value 3 we can't make value using 2 rupee coin put 0 and for value
    4 we can use two two rupee coins so put 1.
    iv) for rest other [row][columns] if column number is less than the denomination of that row just copy the above row value.
    v) else you put val1 + val2 (val1 ? -> explained later) at that [row][column] where val1 is value of index of that row but 
    column one unit less. suppose you are filling row = 5 and column = 3 then, val1 is value of row 4 and column 3.
    and val2 is value of that index in 2D matrix where row is same as that of we are filling but column is original column that
    we are filling minus denomination (that is present in sorted denomination array) at that row index. for example we are 
    filling 2D matrix at row = 3 and column = 6 and then val1 will be value from matrix at index row = 2 and column = 6 and 
    val2 will be value from the matrix at index row = 3 (same as that of that index we are filling) and columin will be original 
    column that we are filling that is 6 minus denomination at row 3, (we will find this using that array where we have kept all
    denominations in ascending order). suppose denomination at index 3 is 4 then, for val2 will be equal to value from the matrix 
    at index row = 3 and column = 4. We will add val1 and val2 and keep there.

7. That's all the process for building the matrix. In the last the value stored at the last row and last column will be the answer
   to question that in how many ways we can make the value using the coin denominations provided.
8. I can understand, this can be tough to understand here without any illustration so, here is a link to understand better 
   { https://youtu.be/L27_JpN6Z1Q?si=W0JzTNkZTqjKKNHl } or else try making matrix through reading the codes. 
9. It will make things more clear and feel free to explore the code provided above.
10. Time complexity - O(no of denominations * value to be founded)
*/