#include <stdio.h>

#define SIZE 5
void print_array(int array[], int n);
void array_reverse(int array[], int n);
int main(){

    int arr[SIZE] = { 1, 2, 3, 4, 5};
    int n = SIZE;

    print_array( arr , n);
    array_reverse(arr, n);
    print_array( arr , n);
//    print_array( &(arr[0]) , n);

}
void array_reverse(int array[], int n){

    // swap first and (n-1)th 
    // swap second and (n-2)th ...

    int i, temp;
    for(i=0; i < n/2; i++){
        temp = array[i];
        array[i] = array[n-1-i];
        array[n-1-i] = temp;
    }

}
void print_array(int array[], int n){

    int i;
    for(i=0;i<n;i++)
        printf("%d ", array[i]);

    printf("\n");
}

