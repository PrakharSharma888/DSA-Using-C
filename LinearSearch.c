#include<stdio.h>

void linear(int arr[], int n, int key){
    int found;
    for(int i= 0 ; i<n; i++){
        if(key == arr[i]){
            found = 1;
            break;
        }
        else{
            found = -1;
        }
    }
    if(found == 1){
        printf("Found");
    }
    else{
        printf("Not found");
    }
}

void main(){
    int n, key;
    int arr[100];
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    printf("\nEnter the values of the array :");
    for(int i = 0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the key :");
    scanf("%d",&key);
    linear(arr,n,key);
}