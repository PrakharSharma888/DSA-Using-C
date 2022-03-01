#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct node *new;
struct node *prev;

struct node * create(){
    struct node * new = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data for the node (-1 for no node) : ");
    scanf("%d", &new->data);
    if(new->data == -1){
        return NULL;
    }
    printf("\nEntering left node for %d ",new->data);
    new->left = create();
    printf("\nEntering right node for %d ",new->data);
    new->right = create();
    return new;
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}

struct node * inorderPre(struct node * root){
    root = root->left;
    while(root->right != NULL){
        root = root -> right;
    }
    return root;
}

struct node * deletion(struct node * root, int value){
    struct node * inPre;
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }

    if(value < root->data){
        root->left = deletion(root->left, value);
    }
    else if(value > root->data){
        root -> right = deletion(root->right, value);
    }
    else{
        inPre = inorderPre(root);
        root->data = inPre->data;
        root-> left = deletion(root->left, inPre->data);

    }
    return root;
}

void main(){
    struct node *root;
    root = NULL;
    root = create();
    int value = 3;
    inorder(root);
    printf("\n");
    deletion(root,value);
    printf("\n");
    inorder(root);
}