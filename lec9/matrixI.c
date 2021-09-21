#include <stdio.h>



int main(){
    int n;
    printf("Type n for Identity matrix:");
    scanf("%d", &n);


    int i, j;

    for(i=0;i<n ; i++){ //for col
        for(j=0;j<n ; j++){ //for row
            if(i==j){
                printf("1 ");
                if( i== 1)
                    break;
            }
            else
                printf("0 ");
        }

        if(i==1)
            break;
        printf("\n");
    }
}
