#include <stdio.h>
#define n 5
int queue[n];
int front = -1;
int rear = -1;

void enqueue()
{
    if (rear == -1 && front == -1)
    {
        front = rear = 0;
        printf("\nEnter data : ");
        scanf("%d", &queue[rear]);
    }
    else if (rear == n - 1)
    {
        printf("\nOverflow!");
    }
    else
    {
        rear++;
        printf("\nEnter data : ");
        scanf("%d", &queue[rear]);
    }
}

void dequeue()
{
    if (rear == -1 && front == -1)
    {
        printf("\nUnderflow!");
    }
    else if (rear == front)
    {
        rear = front = -1;
        printf("\nDone!");
    }
    else
    {
        front++;
        printf("\nDone!");
    }
}

void display()
{
    if (rear == -1 && front == -1)
    {
        printf("\nQueue empty!");
    }
    for (int i = front; i <= rear; i++)
    {
        printf("%d  ", queue[i]);
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