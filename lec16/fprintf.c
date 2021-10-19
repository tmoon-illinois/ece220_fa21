#include <stdio.h>

int main(){
    int uid;
    char name[20];
    double gpa;


    FILE *fp1, *fp2;

    if( (fp1 = fopen("data.txt", "r")) == NULL){
        printf("cannot open data.txt\n");
        return -1;
    }
    if( (fp2 = fopen("swapped.txt", "w")) == NULL){
        printf("cannot open swapped.txt\n");
        return -1;
    }

    int rt;

    while(1){
        rt = fscanf(fp1, "%d %s %lf", &uid, name, &gpa);
        if(rt == EOF)
            break;
        fprintf(fp2, "%s %d %lf\n", name, uid, gpa);
    }
    fclose(fp1);
    fclose(fp2);





}
