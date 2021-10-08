#include <stdio.h>

int linear_search(int array[], int L, int H, int key);
int binary_search(int array[], int L, int H, int key);
void print_1D(int array[], int n);
int main(){
    int array[5] = {1, 3, 10, 11, 20};

    print_1D(array, 5);
    int key_index, key;
    printf("type key value to search: ");
    scanf("%d", &key);
    //key_index = linear_search(array, 0, 4, key);
    key_index = binary_search(array, 0, 4, key);
    printf("key index = %d\n", key_index);

    return 0;
}

void print_1D(int array[], int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d ", array[i]);
    printf("\n");
}
int linear_search(int array[], int L, int H, int key){
    int i;
    for(i=L; i<H; i++){
        if(array[i] == key)
            return i;
    }
    return -1; // no key item in array
}
int binary_search(int array[], int L, int H, int key){
    int M;
    while( L <= H ){
        M = (L+H)/2;
        if(array[M] == key)
            return M;
        else if(array[M] < key)
            L = M+1;
        else // array[M] > key
            H = M-1;
    }

    return -1;
}
