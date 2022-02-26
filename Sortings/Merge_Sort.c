#include <stdio.h>
int n;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}

void merge(int arr[], int mid, int low, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int Helper[100];
    while (i <= mid && j <= high)
    {
        
        if (arr[i] < arr[j])
        {
            printf("hehee");
            Helper[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            Helper[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i<=mid)
    {
        Helper[k] = arr[i];
        i++;
        k++;
    }
    while(j<=high){
        Helper[k] = arr[j];
        j++;
        k++;
    }
    
    for (int i = low; i <= high; i++)
    {
        arr[i] = Helper[i];
    }
}

void mergesort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, mid, low, high);
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

    mergesort(arr, 0, n - 1);
    print(arr, n);
}