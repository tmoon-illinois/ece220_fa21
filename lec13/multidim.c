#include <stdio.h>


#define ROW 2
#define COL 3

//VLA (Variable length array)
void print_2D(int col_size , int a[][col_size]);
void print_2D_ptr(int *a);
int matrix_change(int matrix[ROW][COL], int x, int y);
int main(){
    int arr[ROW][COL] = {{1, 2, 3}, {4, 5, 6}};

    print_2D(COL, arr);
    matrix_change(arr, 0, 1);
    print_2D_ptr(&arr[0][0]);//
    //    print_2D_ptr(arr);//
}

//void print_2D(int a[][COL]){
void print_2D(int col_size, int a[][col_size] ){
    int i,j;

    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
void print_2D_ptr(int *a){
    int i,j;

    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            printf("%d ", a[i*COL+j]);
        }
        printf("\n");
    }
}

int matrix_change(int matrix[ROW][COL], int x, int y){

    int temp, j;
    if( x < 0 || y <0 || x>=ROW || y>=ROW)
        return -1;
    for(j=0;j<COL;j++){
        temp = matrix[x][j];
        matrix[x][j] = matrix[y][j];
        matrix[y][j] = temp;
    }
    return 0;
}

