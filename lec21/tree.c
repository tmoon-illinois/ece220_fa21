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
void DeleteTree(t_node *node);
t_node *InsertBST(t_node *node, int data);
t_node *BSTSearch(t_node *node, int key);
t_node *FindMin(t_node *node);
t_node *FindMax(t_node *node);
int getHeight(t_node *node);

int main(){
    t_node *root = NULL;

/*
    root = NewNode(1);
    root->left = NewNode(2);
    root->right = NewNode(3);
    root->left->left = NewNode(4);
*/

    root = InsertBST(root, 8);
    root = InsertBST(root, 3);
    root = InsertBST(root, 10);
    root = InsertBST(root, 1);
    root = InsertBST(root, 6);
    root = InsertBST(root, 9);
    root = InsertBST(root, 7);
    root = InsertBST(root, 2);
    
    root = InsertBST(root, 0);
    root = InsertBST(root, 100);
    root = InsertBST(root, -9);
    
    printTree(root, 0);


    t_node *temp, *max, *min;
    int key;
    printf("Enter the key value to search: ");
    scanf("%d", &key);
    temp = BSTSearch(root, key);
    if(temp == NULL)
        printf("No such item in the tree.\n");
    else
        printf("Found %d. \n", temp->data);


    max = FindMax(root);
    min = FindMin(root);
    printf("Max value: %d, Min value: %d\n", max->data, min->data);


    printf("Height of the tree: %d\n", getHeight(root));


    printf("preorder: ");
    preorder(root);
    printf("\n");
    
    printf("inorder: ");
    inorder(root);
    printf("\n");

    printf("postorder: ");
    postorder(root);
    printf("\n");

    DeleteTree(root);
    root = NULL;
    printTree(root, 0);
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
void DeleteTree(t_node *node){
    if(node == NULL)
        return;
    else{
        DeleteTree(node->left);
        DeleteTree(node->right);
        printf("Deleting node %d\n", node->data);
        free(node);
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
t_node *InsertBST(t_node *node, int data){
    if(node == NULL){
        return NewNode(data);
    }
    else{
        if(data < node->data)
            node->left = InsertBST(node->left, data);
        else if(data > node->data)
            node->right = InsertBST(node->right, data);

        return node;
    }
}
t_node *BSTSearch(t_node *node, int key){
    if(node == NULL)
        return NULL;
    
    if(node->data == key)
        return node;
    else if(key < node->data)
        return BSTSearch(node->left, key);
    else if(key > node->data)
        return BSTSearch(node->right, key);
}
t_node *FindMin(t_node *node){
    if(node->left == NULL)
        return node;

    else
        return FindMin(node->left);
}
t_node *FindMax(t_node *node){
    if(node->left == NULL)
        return node;

    else
        return FindMax(node->right);
}
int getHeight(t_node *node){
    if(node == NULL)
        return -1;
    else{
        int lh, rh;
        lh = getHeight(node->left);
        rh = getHeight(node->right);
        if(lh > rh)
            return lh + 1;
        else
            return rh + 1;
    }
}









