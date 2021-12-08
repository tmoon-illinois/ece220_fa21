#include <stdio.h>
#include <stdlib.h>

typedef struct node_t{
    int data;
    struct node_t* left;
    struct node_t* right;
}node;


void padding(char ch, int n){
    int i;
    for(i=0;i<n;i++)
        putchar(ch);
}
void printTree(node *root, int level){
    if(root == NULL){
        padding('\t',level);
        printf("*\n");

    }
    else{
        printTree(root->right,level+1);
        padding('\t', level);
        printf("%d\n", root->data);
        printTree(root->left, level+1);
    }
}
int countNeg(node* root){
    if(root == NULL)
        return 0;
    int left_sub, right_sub;

    left_sub = countNeg(root->left);
    right_sub = countNeg(root->right);


    if(root->data < 0 )
        return left_sub + right_sub + 1;
    else
        return left_sub + right_sub;

}
int isSame(node* root1, node* root2){
    if(root1 == NULL && root2 == NULL)
        return 1;
    else if (root1 != NULL && root2 != NULL){
        int left_sub, right_sub;
        left_sub = isSame(root1->left, root2->left);
        right_sub = isSame(root1->right, root2->right);
        return left_sub && right_sub && (root1->data == root2->data);
    }
    // root1 is empty and root 2 is not empty
    //or root1 is not empty and root2 is empty
    else
        return 0;
}
void mirror(node* root){
    if(root == NULL)
        return;

    mirror(root->left);
    mirror(root->right);

    node *temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;

}
node* addNode(int data){
    node *temp = (node*) malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

int main(){

    node *root1 = NULL;
    root1 = addNode(1);
    root1->left = addNode(2);
    root1->right = addNode(2);
    root1->right->left = addNode(0);

    printTree(root1, 0);

    node *root2 = NULL;
    root2 = addNode(1);
    root2->left = addNode(2);
    root2->right = addNode(4);
    root2->right->right= addNode(0);

    printTree(root2, 0);

    printf("Num of neg: %d\n", countNeg(root1));
    printf("is same?: %d\n", isSame(root1, root2));

    mirror(root1);
    printTree(root1, 0);
}




