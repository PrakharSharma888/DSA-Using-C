// log(h) - h is the hieght if the tree

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
};


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

struct node * searching(struct node * root, int key){
    if(root == NULL){
        return NULL;
    }
    else if (root->data == key)
    {
        return root;
    }
    else if(root->data > key){
        return searching(root->left, key);
    }
    else{
        return searching(root->right, key);
    }
}

void main(){
    struct node * root;
    root = NULL;
    root = create();
    int key = 1;
    struct node * p = searching(root,key);
    if(p == NULL){
        printf("\nElement not found ");
    }
    else{
        printf("\nFound element : %d ",p->data);
    }
}