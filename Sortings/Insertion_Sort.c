#include<stdio.h>
int arr[100];
int n;

void insertion(){
    int j, key;

    for(int i = 1; i<=n-1; i++){
        j = i-1;
        key = arr[i];
        
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void print(){
    for(int i = 0; i<n ; i++){
        printf("%d  ",arr[i]);
    }
}

void main(){
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("\nEnter your unsorted array: ");
    for(int i = 0; i<n ; i++){
        scanf("%d",&arr[i]);
    }
    insertion();
    print();
}