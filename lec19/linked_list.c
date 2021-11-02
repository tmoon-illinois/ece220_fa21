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
void insert_sorted_GPA(node **headpptr, node *data);
void delete_all(node **headpptr);
int delete_node(node **headpptr, int UIN);
void push(node **headpptr, node *data);
void pop(node **headpptr);
void enqueue(node **headpptr, node *data);
void dequeue(node **headpptr);

int main(){
    node *headptr = NULL;

    node s;

    // first node
    s.uin = 1;
    s.netid = (char*) malloc(sizeof("aaa") + 1);
    strcpy(s.netid, "aaa");
    s.gpa = 3.0;
    //insert_head(&headptr, &s);
    //push(&headptr, &s);
    enqueue(&headptr, &s);

    // second node
    s.uin = 2;
    s.netid = (char*) malloc(sizeof("bbb") + 1);
    strcpy(s.netid, "bbb");
    s.gpa = 2.0;
    //insert_head(&headptr, &s);
    //push(&headptr, &s);
    enqueue(&headptr, &s);


    // third node
    s.uin = 3;
    s.netid = (char*) malloc(sizeof("ccc") + 1);
    strcpy(s.netid, "ccc");
    s.gpa = 2.5;
    //insert_head(&headptr, &s);
    //push(&headptr, &s);
    enqueue(&headptr, &s);

    printStudents(headptr);

    dequeue(&headptr); 
    printStudents(headptr);
    dequeue(&headptr); 
    printStudents(headptr);
    dequeue(&headptr); 
    printStudents(headptr);
    
    dequeue(&headptr); 
    printStudents(headptr);

    /*
    printf("delete uin=2\n");
    delete_node(&headptr, 2);
    printStudents(headptr);

    delete_all(&headptr);
    printStudents(headptr);
*/
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
void insert_sorted_GPA(node **headpptr, node *data){
    node *temp = (node*) malloc(sizeof(node));
    *temp = *data;
    while(*headpptr &&  (*headpptr)->GPA > data->GPA)
        headpptr = &((*headpptr)->next);

    temp->next = *headpptr;
    *headpptr = temp;
}
void delete_all(node **headpptr){
    node *next;
    while(*headpptr != NULL){
        next = (*headpptr)->next;
        free((*headpptr)->netid);
        free(*headpptr);
        *headpptr = next;
    }
    *headpptr = NULL;
}
int delete_node(node **headpptr, int UIN){
    node *target;
    while( *headpptr != NULL && (*headpptr)->uin != UIN)
        headpptr = &((*headpptr)->next);
    if(*headpptr == NULL) return 0;

    target = *headpptr;
    *headpptr = target->next;
    free(target->netid);
    free(target);
    return 1;


}

void push(node **headpptr, node *data){
    node *temp = (node*) malloc(sizeof(node));
    *temp = *data;

    temp->next = *headpptr;
    *headpptr = temp;
}
void pop(node **headpptr){

    node *next;

    if(*headpptr == NULL){
        printf("stack is empty.\n");
        return;
    }

    next = (*headpptr)->next;
    free((*headpptr)->netid);
    free(*headpptr);
    *headpptr = next;
}
void enqueue(node **headpptr, node *data){
    node *temp = (node*) malloc(sizeof(node));
    *temp = *data;
    temp->next = NULL;

    while(*headpptr != NULL)
        headpptr = &((*headpptr)->next);
    
    *headpptr = temp;
}
void dequeue(node **headpptr){
    node *next;

    if(*headpptr == NULL){
        printf("Queue is empty.\n");
        return;
    }

    next = (*headpptr)->next;
    free((*headpptr)->netid);
    free(*headpptr);
    *headpptr = next;
}





