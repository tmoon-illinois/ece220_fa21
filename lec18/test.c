#include <stdio.h>
#include <stdlib.h>

int main(){
    /*
    int *ptr1 = (int*) malloc(sizeof(int));
    int *ptr2;
    ptr2 = malloc(sizeof(int));

    *ptr1 = 10;
    *ptr2 = 20;
    free(ptr1);
    ptr1 = ptr2;
    free(ptr2);
*/

    int size = 5, i;
    int *ptr1 = (int*) malloc(size*sizeof(int));
    int *ptr2 = (int*) calloc(size, sizeof(int));

    printf("1st trial\n");
    printf("malloc\n");
    for(i=0;i<size;i++){
        printf("%d ", ptr1[i]);
        //printf("%d ", *(ptr1+i));
    }
    printf("\n");
    printf("calloc\n");
    for(i=0;i<size;i++){
        printf("%d ", ptr2[i]);
    }
    ptr1[0] = 100;
    ptr2[0] = 100;

    free(ptr1);
    free(ptr2);
    
    printf("\n\n2nd trial\n");
    ptr1 = (int*) malloc(size*sizeof(int));
    ptr2 = (int*) calloc(size, sizeof(int));

    printf("malloc\n");
    for(i=0;i<size;i++){
        printf("%d ", ptr1[i]);
        //printf("%d ", *(ptr1+i));
    }
    printf("\n");
    printf("calloc\n");
    for(i=0;i<size;i++){
        printf("%d ", ptr2[i]);
    }

    free(ptr1);
    free(ptr2);
    return 0;
}
