#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student{
    int uin;
    char *netid;
    float gpa;
    struct Student *next;
}node;

void insert_head(node **headpptr, node *data);
void printStudents(node *cursor);

int main(){
    node *headptr = NULL;

    node s;

    // first node
    s.uin = 1;
    s.netid = (char*) malloc(sizeof("aaa") + 1);
    strcpy(s.netid, "aaa");
    s.gpa = 3.0;
    insert_head(&headptr, &s);

    // second node
    s.uin = 2;
    s.netid = (char*) malloc(sizeof("bbb") + 1);
    strcpy(s.netid, "bbb");
    s.gpa = 2.0;
    insert_head(&headptr, &s);


    // third node
    s.uin = 3;
    s.netid = (char*) malloc(sizeof("ccc") + 1);
    strcpy(s.netid, "ccc");
    s.gpa = 2.5;
    insert_head(&headptr, &s);

    printStudents(headptr);
}

void insert_head(node **headpptr, node *data){
    node *temp = (node*) malloc(sizeof(node));
    *temp = *data;

    temp->next = *headpptr;
    *headpptr = temp;
}
void printStudents(node *cursor){

    printf("uin netid gpa\n");
    while(cursor != NULL){
        printf("%d %s %f\n", cursor->uin, cursor->netid, cursor->gpa);
        cursor = cursor ->next;
    }
}









