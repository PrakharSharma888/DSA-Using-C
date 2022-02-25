// niether adaptive nor stable 
// O(n2) in all cases

#include<stdio.h>
int arr[100];
int n;

void selection(){
    int temp;
    for(int i=0; i<n-1; i++){
        for(int j= i+1; j<n ; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
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
    selection();
    print();
}