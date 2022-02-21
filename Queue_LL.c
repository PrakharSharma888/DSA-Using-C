#include <stdio.h>
#include <stdlib.h>


struct queue
{
    int data;
    struct queue *next;
};

struct queue *rear = NULL;
struct queue *front = NULL;
struct queue *new, *temp;


void enqueue(){
    if(rear==NULL && front==NULL){
        new = (struct queue*)malloc(sizeof(struct queue));
        printf("\nEnter data :");
        scanf("%d",&new->data);
        temp = front = rear = new;
        rear->next = NULL;
        front->next = NULL;
    }
    else{
        new = (struct queue*)malloc(sizeof(struct queue));
        printf("\nEnter data :");
        scanf("%d",&new->data);
        rear->next = new;
        rear = new;
        rear->next = NULL;
    }
}

void dequeue(){
    if(front==rear){
        front = NULL;
        printf("\nDone the last");
    }
    else if(front == NULL){
        printf("\nQueue empty!");
    }
    else{
        front = front->next;
        printf("\nDone");
    }
}

void display(){
    temp = front;
    while(temp!=NULL){
        printf("%d  ",temp->data);
        temp = temp->next;
    }
}

void main()
{
    int ch;
    do
    {
        printf("\nChoose your operation\n1)Enqueue\n2)Dequeue\n3)Display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        default:
            printf("Wrong Choice!");
            break;
        }
    } while (ch != 0);
}