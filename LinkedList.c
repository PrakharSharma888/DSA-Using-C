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

void insert(struct node* new, int n)
{
    int index;
    struct node* p,*q;
    p=head;
    printf("\nWhere do you want to insert? ");
    scanf("%d", &index);
    if (index == 1)
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data : ");
        scanf("%d",&new->data);
        new->next = head;
        head = new;
    }
    else if(index==n){
        new = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data :");
        scanf("%d",&new->data);
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=new;
        new->next=NULL;
    }
    else{
        int i=1;
        while(i<index-1){
            p = p->next;
            i++;
        }
        q = p->next;
        new = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data :");
        scanf("%d",&new->data);
        new->next = p->next;
        p->next = new;
    }
}

void del(int size)
{
    int index;
    struct node* p,*q;
    p=head;
    printf("\nWhere do you want to Delete? ");
    scanf("%d", &index);
    if (index == 1)
    {
        p = head;
        head = head->next;
        free(p);
    }
    else if(index==size-1){
        while(p->next->next!=NULL){
            p=p->next;
        }
        q = p->next;
        p->next = NULL;
        free(q);
    }
    else{
        int i=1;
        while(i<index-1){
            p = p->next;
            i++;
        }
        q = p->next;
        p->next = q->next;
        free(q);
    }
}

int count(){
    int count = 0;
    temp = head;
    while(temp->next!=NULL){
        count ++;
        temp = temp->next;
    }
    return count;
}

void main()
{
    int size;
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
            insert(new,n);
            break;
        case 2:
            size = count();
            del(size);
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