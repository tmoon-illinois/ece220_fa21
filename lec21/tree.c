#include <stdio.h>
#include <stdlib.h>

typedef struct nodeTag t_node;
struct nodeTag
{
    int data;
    t_node *left;
    t_node *right;
};

void padding(char ch, int n);
void printTree(t_node *node, int level);
t_node* NewNode(int data);
void preorder(t_node *node);
void inorder(t_node *node);
void postorder(t_node *node);

int main(){
    t_node *root = NULL;


    root = NewNode(1);
    root->left = NewNode(2);
    root->right = NewNode(3);
    root->left->left = NewNode(4);

    printTree(root, 0);

    printf("preorder: ");
    preorder(root);
    printf("\n");
    
    printf("inorder: ");
    inorder(root);
    printf("\n");

    printf("postorder: ");
    postorder(root);
    printf("\n");
}


t_node* NewNode(int data){
    t_node *node = (t_node*) malloc(sizeof(t_node));
    node->data = data;
    node->left = NULL;
    node->right= NULL;
}


void preorder(t_node *node){
    if(node == NULL)
        return;
    else{
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}
void inorder(t_node *node){
    if(node == NULL)
        return;
    else{
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}
void postorder(t_node *node){
    if(node == NULL)
        return;
    else{
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}
void padding(char ch, int n)
{
    int i;
    for(i=0;i<n;i++)
        putchar(ch);
}
void printTree(t_node *node, int level)
{
    if(node == NULL){
        padding('\t',level);
        printf("*\n");

    }
    else{
        printTree(node->right,level+1);
        padding('\t', level);
        printf("%d\n", node->data);
        printTree(node->left, level+1);
    }
}

