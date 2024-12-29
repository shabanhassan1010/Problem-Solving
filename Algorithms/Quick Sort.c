#include <stdio.h>
#include <stdlib.h>

int partition(int arr[] , int L , int H)
{
    int i = L; // stand in the first index in the array
    int j = H; // stand in the outside of the array
    int pivot = arr[i]; // start from the first element in the arr
    do{
        do{ i++; } while(i <= pivot);
        do{ j--; } while(j >= pivot);
        if(i < j)
        {
            // Swapping between i >>> k
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }while (i < j);
        // Place the pivot in the correct position
            int temp = arr[L];
            arr[L] = arr[j];
            arr[j] = temp;

            return j; // Return the partition index
}

void quickSort(int arr[], int L, int H) 
{
    if (L < H) {
        // Partition the array
        int p = partition(arr, L, H);
        // Recursively sort the subarrays
        quickSort(arr, L, p);
        quickSort(arr, p + 1, H);
    }
}
void printFun(int arr[] , int size)
{
    for(int i = 0 ; i < size-1 ; i++)
    {
        printf("%d  " , arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = 6;

    printf("Original array:\n"); 
    printFun(arr, n);

    quickSort(arr, 0, n);

    printf("Sorted array:\n");
    printFun(arr, n);

    return 0;
}