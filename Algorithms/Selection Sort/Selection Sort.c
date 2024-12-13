#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int arr[] , int size)
{
    int k , j;
    for(int i = 0 ; i < size -1 ; i ++)
    {
        for(j=k=i ; j < size ; j++)
        {
            if(arr[j] < arr[k])
            {
                k = j;
            }
        }
        // Swapping between i >>> k
            int temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
    }
}



int main()
{
    int arr [] = {9 , 19 , 2 , 12 , 4 , 7 , 9};
    SelectionSort(arr , 7);
    for(int i = 0 ; i < 7 ; i++)
    {
        printf("%d"  , arr[i]);
        printf("%d");
    }
   
 
 return 0;
}