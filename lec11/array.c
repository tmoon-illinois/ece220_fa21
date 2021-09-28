#include <stdio.h>

int main(){
    int grid[10] = {1,2,3, 4, 5,6, 7, 8, 9, 10};

    int i;

    grid[10] = 10; // not valid 

    for(i=0;i<10;i++)
        printf("%d\n", grid[i]);


    return 0;
}

