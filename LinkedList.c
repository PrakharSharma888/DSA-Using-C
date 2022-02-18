#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *temp;

void newnode(struct node *new)
{

    if (head == NULL)
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter Data for the head node : ");
        scanf("%d", &new->data);
        head = temp = new;
        temp->next = NULL;
    }
    else
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter Data for the next node : ");
        scanf("%d", &new->data);
        temp->next = new;
        temp = new;
        new->next = NULL;
    }
}

void traversal(struct node *temp)
{
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

void insert(struct node* new)
{
    int index;
    printf("\nWhere do you want to insert? ");
    scanf("%d", &index);
    if (index == 0)
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data");
        scanf("%d",&new->data);
        new->next = head;
        head = new;
    }
}

void del()
{
}

void main()
{
    int n, ch, i = 1;
    struct node *new, *temp;

    printf("Enter the number of nodes you want : ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        newnode(new);
    }
    do
    {
        printf("\nChoose your option\n1)Insertion\n2)Deletion\n3)Display\n4)Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert(new);
            break;
        case 2:
            del();
            break;
        case 3:
            temp = head;
            traversal(temp);
            break;
        case 4:
            i = 0;
            break;
        default:
            printf("Wrong Entry");
            break;
        }
    } while (i);
}