#include<stdio.h>
#include<stdlib.h>

struct queue{
    int data;
    struct queue *next;
};

struct queue *rear = NULL;
struct queue *front = NULL;
struct queue *new;

void enqueue(){
    if(rear == NULL && front == NULL){
        new = (struct queue*)malloc(sizeof(struct queue));
        printf("\nEnter data : ");
        scanf("%d",&new->data);
        rear = front = new;
        rear->next = front;
    }
    else{
        new = (struct queue*)malloc(sizeof(struct queue));
        printf("\nEnter data : ");
        scanf("%d",&new->data);
        rear->next = new;
        rear = new;
        rear->next = front;
    }
}

void dequeue(){
    if(front == rear){
        front = rear = NULL;
        printf("\nDeleted");
        printf("\nlist is now empty");
    }
    else{
        front=front->next;
        rear->next = front;
        printf("\nDeleted");
    }
}

void display(){
    new = front;
    while(new->next!=front){
        printf("%d  ",new->data);
        new = new->next;
    }
    printf("%d  ",rear->data);
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