#include <stdio.h>
int arr[100];

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int temp, i = low + 1;
    int j = high;
    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

    } while (i < j);

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void quick(int arr[], int low, int high)
{
    int partitionIndex;

    if (low < high)
    {
        partitionIndex = partition(arr, low, high);
        quick(arr, low, partitionIndex - 1);  // left subarray
        quick(arr, partitionIndex + 1, high); // right subarray
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}

void main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("\nEnter your unsorted array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    quick(arr, 0, n - 1);
    print(arr, n);
}