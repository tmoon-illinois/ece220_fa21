#include <stdio.h>
#include <string.h>

void string_copy(char des[], char src[]);
int main(){

    char buf[20] = "D"; 

    printf("%s\n", buf);
   // string_copy(buf, "ABC");
    strcpy(buf, "ABC");
    printf("%s\n", buf);


    scanf("%s", &buf[0]);
 //   scanf("%s", buf);
    printf("%s", buf);
}

void string_copy(char des[], char src[]){
    int i=0;

    while(src[i] != '\0'){
        des[i] = src[i];
        i++;
    }
    des[i] = '\0';
}
