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

struct node * searchIter(struct node * root, int key){
    
    while(root!=NULL){
        if(key == root->data){
            return root;
        }
        else if(key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
}

void main(){
    struct node * root;
    root = NULL;
    root = create();
    int key = 2;
    struct node * p = searchIter(root,key);
    if(p == NULL){
        printf("\nElement not found ");
    }
    else{
        printf("\nFound element : %d ",p->data);
    }
}