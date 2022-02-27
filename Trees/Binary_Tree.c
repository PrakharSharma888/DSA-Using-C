// n nodes and n-1 edges
// most 2 childs
// degree - no. of children
// drgree of tree - highest degree of nodes
// types - $ Full or Strict Binary tree(0 or 2 nodes)
//       - $ Perfect Binary tree(2 nodes, same level nodes)
//       - $ Complete Binary tree(All levels completly filled 
//           except last level that should be left aligned)
//       - $ Degenerate tree(Exaclty one child to all)

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node * root;

struct node * create(){
    struct node *new = (struct node*) malloc(sizeof(struct node));
    printf("\nEnter data for the node (-1 for no new node) : ");
    scanf("%d",&new->data);
    if(new->data == -1){
        return NULL;
    }
    printf("\nEntering left child of the node -> %d: ",new->data);
    new->left = create();
    printf("\nEntering right child of the node -> %d: ",new->data);
    new->right = create();
    return new;
}

void main(){
    struct node *root;
    root = NULL;
    root = create();
}
