// O(n)
// extra space leta he but

#include <stdio.h>
int n;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}

int getMax(int arr[]){
    int length = sizeof(arr)/sizeof(arr[0]);     // to find the length of the new array 
    int max = arr[0];   

    for (int i = 0; i < length; i++) {        
    if(arr[i] > max)    
        max = arr[i];    
    } 
    return max;
}

void CountSort(int arr[], int n){
    int max;
    int b[100];
    int output[n-1];
    
    max = getMax(arr);
    int count[20];
    for (int i = 0; i < max; i++) // initializing all with 0
    {
        count[i] = 0;
    }
    
    int length = sizeof(count)/sizeof(count[0]);
    for(int i = 0; i<n; i++){  // to get the no. of occurences of the array
        count[arr[i]]++;     
    }

    for (int i = 0; i < length; i++)
    {
        count[i] += count[i-1]; // adding all one by one
    }
    
    for(int i = n-1; i>=0; i--){
        output[count[arr[i]] - 1] = arr[i];  
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void main()
{
    int n;
    int arr[100];
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("\nEnter your unsorted array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    CountSort(arr,n);
    print(arr, n);
}