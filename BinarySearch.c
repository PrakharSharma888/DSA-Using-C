#include<stdio.h>

void binary(int arr[], int n, int key){
    int mid,low,high;
    low = 0;
    high = n-1;
    mid = (low+high)/2;
    while(low<=high){

        if(arr[mid] == key){
            printf("\nFound at %d",mid);
            break;
        }
        else if (arr[mid]>key)
        {
            high = mid-1;
            mid = (low+high)/2;
        }
        else{
            low = mid+1;
            mid = (low+high)/2;
        }
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
    binary(arr,n,key);
}