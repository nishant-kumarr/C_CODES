/* 
THIS PROGRAM IS RESPONSIBLE FOR ROTATING A MATRIX IN ANTI-CLOCKWISE DIRECTION 
*/

#include<stdio.h>

void rotate(int r, int c, int a[r][c]){  /* THIS FUNCITON IS CAPABLE OF ROTATING MATRIX OF 3x3 OR HIGHER ORDER*/
    int i=0 , j = 0, temp, prev, backup;
    prev = a[i][j+1],backup = a[i][j+2];


    while(1){
        temp = a[i][j];
        a[i][j] = prev;
        prev = temp;

        if(i < r-1 && j == 0){
            ++i;
        }
        else if((i == r-1 && j == 0) || (i == r-1 && j < c-1)){
            ++j;
        }
        else if((i > 0 || i == r-1) && j == c-1){
            --i;
        }
        else if(i == 0 && (j > 1 || j == c-1)){
            --j;
        }
        else if( i == 0 && j == 1){
            a[i][j] = backup;
            break;
        }
    }
}

void rotateless(int r, int c, int a[r][c]){       /* THIS FUNCTION WILL DEAL WITH 2x2 MATRIXES ONLY */
    int i=0, j=0;
    int backup = a[0][0];

    while(1){
        if(i==0 && j==0){
            a[i][j] = a[i][j+1];
            j++;
        }
        else if(i == 0 && j == 1){
            a[i][j] = a[i+1][j];
            i++;
        }
        else if(i == 1 && j == 1){
            a[i][j] = a[i][j-1];
            j--;
        }
        else if(i == 1 && j == 0){
            a[i][j] = backup;
            break;
        }

    }
}

int main(){         /* TAKING MATRIX ORDER AND ITS DATA THEN PRINT ORIGINAL FOLLOWED BY ROTATED MATRIX */
    int r,c;
    printf("Enter no of rows : ");
    scanf("%d",&r);
    c = r;

    int a[r][c];

    printf("Enter matrix data : ");
    for(int i=0;i<r;i++){
        for(int j= 0 ;j<c;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("\n\tOriginal Matrix : \n");
    for(int i=0; i<r ; i++){
        for(int j=0; j<c ;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    if(r >= 3){
        rotate(r,c,a);
    }
    else if(r < 3){
        rotateless(r,c,a);
    }

    printf("\n\tRotated matrix : \n");
    for(int i=0; i<r ; i++){
        for(int j=0; j<c ;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}