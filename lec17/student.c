#include <stdio.h>

typedef struct StudentStuct{
    int uin;
    char netid[20];
    double gpa;
}student;


int loadFile(char filename[], student s[]);
void printStudents(student s[], int num);
void BubbleSort(student array[], int n);
void swap(student *a, student *b);


int main(){
    student s[100];
    int num;
    char filename[20];

    printf("Enter the data file nema: ");
    scanf("%s", filename);

    num = loadFile(filename, s);
    printf("num = %d\n", num);
    printStudents(s, num);// before sort

    printf("After GPA sort\n");
    BubbleSort(s, num);
    printStudents(s, num);// after sort



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

void BubbleSort(student array[], int n){
    int i;
    int flag_swap;
    do{
        flag_swap = 0;
        for(i = 0; i<n-1 ; i++){
            if(array[i].gpa < array[i+1].gpa ){
                swap(&array[i], &array[i+1]);// 
                flag_swap = 1;
            }
        }
    }while(flag_swap == 1 );
}
void swap(student *a, student *b){
    student temp;

    temp = *a;
    *a = *b;
    *b = temp;
}




