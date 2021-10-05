#include <stdio.h>

int main(){
    int word[10] = {1, 2, 3};
    int *cptr;

    double num[10] = {1.0, 2.0, 3.0};
    double *nptr;
    //word contains the address of word[0]
    cptr = word; 
    nptr = num;

    //cptr = cptr +1 ;
    //word = word + 1;
    //cptr = &word;


    printf("*cptr = %d\n", *cptr);
    printf("*word= %d\n", *word);
    printf("word[0]= %d\n", word[0]);

    printf("*(cptr+2) = %d\n", *(cptr+2));
    printf("*(word+2)= %d\n", *(word+2));
    printf("word[2]= %d\n", word[2]);
    
    printf("*(nptr+2) = %lf\n", *(nptr+2));
    printf("*(num+2)= %lf\n", *(num+2));
    printf("num[2]= %lf\n", num[2]);
}
