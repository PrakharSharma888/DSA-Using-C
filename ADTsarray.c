#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct array{
    int total;
    int used;
    int *ptr;
};

void Create(struct array *a, int tvalue, int tused){
    a->total = tvalue;
    a->used = tused;
    a->ptr = (int*)malloc(tvalue*sizeof(int));
}

void show(struct array *a){
    for(int i = 0; i<a->used; i++){
        printf("%d\t",(a->ptr)[i]);
    }
}

void set(struct array *a){
    for(int i = 0; i<a->used; i++){
        printf("Enter elements for postion %d\n",i);
        scanf("%d",&(a->ptr)[i]);

    }
}

void main(){
    struct array marks;
    Create(&marks, 10, 3);
    set(&marks);
    printf("The elements of the array are :");
    show(&marks);
}
