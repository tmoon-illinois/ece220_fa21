

#include <stdio.h>

int fact(int n);
int fact_rec(int n);

int main(){
    int n = 4;
    printf("Fact by iterative way: %d\n", fact(n));
    printf("Fact by rescursive way: %d\n", fact_rec(n));
}

int fact(int n){
    int i, result = 1;;
    for(i=n; i>0; i--){
        result = result * i;
    }
    return result;
}
   
int fact_rec(int n){

    if(n==1)
        return 1;
    else
        return n*fact_rec(n-1);

}

