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

void insertion(struct node * root, int key){
    new = (struct node *)malloc(sizeof(struct node));
    new->left = NULL;
    new->right = NULL;
    new->data = key;

    if(key < prev->data){
        prev->left = new;
    }
    else{
        prev->right = new;
    }
}

struct node * searchIter(struct node * root, int key){
    while(root!=NULL){
        prev = root;  // 2 - 3 - 4 - '5'- 6
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
    struct node * root,* rootbro;
    int key;
    root = NULL;
    root = create();
    rootbro = root;
    printf("\nEnter your element to be inserted : ");
    scanf("%d",&key);
    struct node * p = searchIter(root,key);
    if(p == NULL){
        insertion(root,key);
    }
    else{
        printf("\nElement already there cant do insertion of dublicate element");
    }
    printf("\n%d",rootbro->right->right->data);
}