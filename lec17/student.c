#include <stdio.h>

typedef struct StudentStuct{
    int uin;
    char netid[20];
    double gpa;
}student;


int loadFile(char filename[], student s[]);
void printStudents(student s[], int num);
int main(){
    student s[100];
    int num;
    char filename[20];

    printf("Enter the data file nema: ");
    scanf("%s", filename);

    num = loadFile(filename, s);
    printf("num = %d\n", num);
    printStudents(s, num);

}
int loadFile(char filename[], student s[]){
    FILE *fp;
    int num = 0;
    char buffer[100];;
    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("No data file in the path.\n");
        return -1;
    }

    fgets(buffer, 100, fp);// skip the header

    while ( fscanf(fp, "%d %s %lf",  &(s[num].uin), s[num].netid, &(s[num].gpa)) != EOF ){
        num++;
    }
    fclose(fp);
    return num;
}
void printStudents(student s[], int num){

    int i;
    for(i=0; i<num; i++)
        printf("%d %s %lf\n", s[i].uin, s[i].netid, s[i].gpa);
}





