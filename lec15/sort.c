#include <stdio.h>



#define SIZE 8
void BubbleSort(int array[], int n);
void swap(int *a, int *b);
void print_1D(int array[], int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d ", array[i]);
    printf("\n");
}

void insertSort(int array[], int n);
void quickSort(int array[], int L, int H);
int partition(int array[], int L, int H);


int main(){
    //int array[SIZE] = {5, 1, 4, 2, 8};
    int array[SIZE] = { 8, 11, 3, 22, 11, 33, 20,  200};

    print_1D(array, SIZE);
    //BubbleSort(array, 5);
    //insertSort(array, SIZE);
    quickSort(array, 0, SIZE-1);
    print_1D(array, SIZE);

    return 0;

}


void BubbleSort(int array[], int n){

    int i;
    int flag_swap;
    do{
        flag_swap = 0;
        for(i = 0; i<n-1 ; i++){
            if(array[i] > array[i+1]){
                swap(&array[i], &array[i+1]);// 
                flag_swap = 1;
            }
        }
        //printf("A\n");
    }while(flag_swap == 1 );

}
void swap(int *a, int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
void insertSort(int array[], int n){

    int unsorted, sorted, unsortedItem;
    for(unsorted = 1; unsorted < n; unsorted++){
        unsortedItem = array[unsorted];
        sorted = unsorted - 1;
        while( array[sorted] >  unsortedItem &&  sorted >= 0  ){
            array[sorted+1] = array[sorted];  // right shift
            sorted--;
        }
        array[sorted+1] = unsortedItem;
    }
}
void quickSort(int array[], int L, int H){
    if(L >= H)
        return;
    int pivot_index = partition(array, L, H);
    quickSort(array, L, pivot_index - 1);
    quickSort(array, pivot_index + 1, H);
}
int partition(int array[], int L, int H){
    int pivot = array[H];
    int i = L-1;
    int j;
    for(j=L; j<=H-1; j++){
        if(array[j] < pivot){
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[H], &array[i+1]);
    return i+1;
}





