#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[] , int size )
{
    for(int i = 1 ; i < size ; i++)
    {
        int j = i-1;
        int x = arr[i];
        while (j > -1 && arr[j] > x)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x;
    }
}

int main()
{
    int arr [] = {9 , 19 , 2 , 12 , 4 , 7 , 9};
    insertionSort(arr , 7);
    for(int i = 0 ; i < 7 ; i++)
    {
        printf("%d"  , arr[i]);
        printf("%d");
    }
   
 
 return 0;
}