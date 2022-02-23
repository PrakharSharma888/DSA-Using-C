#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(){
    struct node * new;
    int x;
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data for the node : \n");
    scanf("%d",&new->data);
    new->next = top;
    top = new;
}

void display(){
    struct node * temp;
    temp = top;
    while(temp!=NULL){
        printf("%d  ",temp->data);
        temp = temp->next;
    }
}

void pop(){
    if(top==NULL){
        printf("\nStack Underflow");
    }
    top = top->next;
}
void main(){
    push();
    push();
    push();
    pop();
    display();
}