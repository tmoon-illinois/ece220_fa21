#include <stdio.h>



int main(){
    int n;
    printf("Type n for Identity matrix:");
    scanf("%d", &n);


    int i, j;

    for(i=0;i<n ; i++){ //for col
        for(j=0;j<n ; j++){ //for row
            if(i==j)
                printf("1 ");
            else
                printf("0 ");
        }
        printf("\n");
    }


}
