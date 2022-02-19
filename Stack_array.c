#include<stdio.h>
#include<conio.h>

#define N 5
int stack[N];
int top =-1;

void push(){
    int x;
    printf("Enter data to be pushed in the stack : ");
    scanf("%d",&x);
    if(top == N-1){
        printf("Stack Overflow");
    }
    else{
        top++;
        stack[top] = x;
        printf("\nElement pushed into the stack");
        printf("%d",stack[top]);
    }
}

void pop(){
    int x;
    if(top == -1){
        printf("Stack Underflow");
    }
    else{
        top--;
        printf("\nThe topmost element has been popped out");
    }
}

void display(){
    if(top==-1){
        printf("Stack is empty");
    }
    else{
        printf("\n%d\n",top);
        for(int i = top; i>=0; i--){
            printf("%d  ",stack[i]);
        }
    }
}
void main(){
    int ch;
    do{
        printf("\nChoose your option:\n1)Push\n2)Pop\n3)Display\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: push();
            break;
        case 2: pop();
            break;
        case 3: display();
            break;
        default: printf("Wrong Entry!");
            break;
        }
    }while(ch!=0);
}