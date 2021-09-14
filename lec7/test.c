#include <stdio.h>

int main()
{

    printf("char: %d, short int: %d, int: %d, long int:%d \n", sizeof(char), sizeof(short int), sizeof(int), sizeof(long int));


    int temp = 0x80000000; // MSB is 1

    printf("%x\n", temp<< 1);

    return 0;
}
