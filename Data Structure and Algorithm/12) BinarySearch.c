/*

Hello, Visitor! Welcome to my code, designed to facilitate Binary search operations on an array.
In this program two different functions are written first function does binary search by recursion while another uses 
iteration to perform the search. User will be asked for which way to use.
Feel free to explore these 'C Data structure' using my code!

*/


#include<stdio.h>

int Bsearch_R(int arr[], int n, int key, int low, int high){
    int mid;
    mid = low + (high-low)/2;

    while(low<=high){
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid]<key){
            low = mid+1;
            return Bsearch_R(arr,n,key,low,high);
        }
        else{
            high = mid-1;
            return Bsearch_R(arr,n,key,low,high);
        }
    }
    return -1;
}

int Bsearch_WR(int arr[], int n, int key, int low, int high){
    int mid;
    mid = low + (high-low)/2;
    while(low<=high){
        if(arr[mid]== key){
            return mid;
        }
        else if(arr[mid]<key){
            low = mid+1;
        }
        else{
            high = mid+1;
        }
	if(low<=high){
	    return -1;
	}
    }
}

int main(){
    int i,n,key,res;
    printf("\nEnter the no of element : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array data : ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }   
    printf("Enter the key to search : ");
    scanf("%d",&key);

    int low = 0,high = n-1;

    printf("\n1. To search recursively");
    printf("\n2. To search without recursion");
    int choice;
    printf("\nEnter your choice : ");
    scanf("%d",&choice);

    if(choice == 1){
        res = Bsearch_R(arr,n,key,low,high);
        if(res == -1){
            printf("%d not found",key);
        }
        else{
            printf("%d found at location %d",key,res+1);
        }
    }
    else if(choice == 2){
        res = Bsearch_WR(arr,n,key,low,high);
        if(res == -1){
            printf("%d not found",key);
        }
        else{
            printf("%d found at location %d",key,res+1);
        }
    }
    else {
        printf("\tWrong choice.");
    }
}