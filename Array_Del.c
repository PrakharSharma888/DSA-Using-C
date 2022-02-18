#include<stdio.h>

void deletion(int index,int size, int arr[]){
    for(int i=index; i<size; i++){
        arr[i] = arr[i+1];
    }
}

void show(int size, int arr[]){
    for(int i=0; i<size; i++){
        printf("%d",arr[i]);
    }
}

void main(){
    int n, index;
    int arr[100];
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    printf("\nEnter the values of the array :");
    for(int i = 0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the index to be deleted");
    scanf("%d",&index);
    deletion(index,n,arr);
    n -= 1;
    show(n,arr);
}