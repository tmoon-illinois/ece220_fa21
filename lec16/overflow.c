#include <stdio.h>


#define SIZE 5
int main(){

    int x = 100;
    char buf[SIZE];

    //fgets(buf, SIZE, stdin);
    scanf("%s", buf);

    printf("buf = %s\n", buf);
    printf("x = %d\n", x);
}


