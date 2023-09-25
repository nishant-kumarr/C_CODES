/* 
THIS PROGRAM IS RESPONSIBLE FOR ROTATION OF A 1D ARRAY AFTER TAKING CHOICE OF CLOCK OR ANTI-CLOCK WISE 
*/

#include<stdio.h>

void rotate_clockwise(int arr[],int size){     /* FUNCTION TO ROTATE CLOCKWISE */
    int i;
    int val = arr[0];
    for(i=0;i<size-1;i++){
        arr[i] = arr[i+1];
    }
    arr[size-1]= val;
    printf("After swap : ");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

void rotateAnti_clockwise(int arr[],int size){      /* FUNCTION TO ROTATE ANTI-CLOCKWISE */
    int i;
    int val = arr[size-1];
    for(i=size-1;i>0;i--){
        arr[i] = arr[i-1];
    }
    arr[0]= val;
    printf("After swap : ");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}
int main(){         /* TAKE ARRAY DATA AND CHOICE OF ROTATION THEN ROTATE AND PRINT IT */
    int i,size,choice;
    printf("Enter 1D array size : ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter array data : ");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Press 1 to rotate clockwise and 2 to Anti-clockwise.");
    printf("\nEnter choice : ");
    scanf("%d",&choice);
    if(choice == 1){
        rotate_clockwise(arr,size);
    }
    else{
        rotateAnti_clockwise(arr,size);
    }
    return 0;
}