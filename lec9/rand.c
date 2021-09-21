



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double GenRand(double a, double b);
int main(){

    int seed, n, i;
    double a, b;

    /*
    printf("Enter a seed number: ");
    scanf("%d", &seed);
    srand(seed);

    */

    srand(time(0));

    printf("Enter the range of rand numbers: ");
    scanf("%lf %lf", &a, &b);

    printf("Enter the number of rand numbers: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("%lf\n", GenRand(a, b));
    }

}

// generate rand number between a and b
double GenRand(double a, double b){

    int x = rand();// 0 - RAND_MAX
    double result;
    // x/RAND_MAX -> 0 to 1
    // (b-a)*x/RAND_MAX -> 0 to (b-a)
    // (b-a)*x/RAND_MAX +a  -> a to b
    //
    result = (b-a)*x/RAND_MAX +a ;
    return result;
}

