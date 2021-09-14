#include <stdio.h>

//#define TIP 0.20

int main()
{

   
    float bill=0, total=0;
    float TIP = 0.2;

    printf("Enter your bill: ");
    scanf("%f", &bill);

    total = bill + bill*TIP;

    printf("Your total is %.2f\n", total);

//    return 0;
}
