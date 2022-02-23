#include <stdio.h>

void bubble(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void print(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
}

void main()
{
    int arr[100];
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("\nEnter the Unsorted Array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    bubble(arr, n);
    print(arr, n);
}