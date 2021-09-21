



#include <stdio.h>
#include <math.h>

//double Riemann(double a, double b, int n);
//double Riemann(double , double , int );

double f(double x);

int main(){
    double a, b;
    int n;

    printf("Enter a, b, n: ");
    scanf("%lf %lf %d", &a, &b, &n); 

    printf("Integral value = %lf\n", Riemann(a, b, n));
}

double f(double x){
    return cos(x);
//    return x;
}
double Riemann(double a, double b, int n){
    double dx, x, result = 0.0;

    int i;
    dx = (b-a)/n;


    for(i=0; i<n; i++){

        x = a + i*dx;
        result = result + dx*f(x);

    }
    return result;
}
