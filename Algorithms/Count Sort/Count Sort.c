#include <stdio.h>
#include <stdlib.h>

//[1] take the max number in the array and declare a new array with this number and also inizilte this array with 0.
//[2] scan elements in the array one by one and for each number in array i will plus it in the new array 

int FindMax(int arr[] , int size)
{
    int max = arr[0];
    for(int i = 0 ; i < size ; i++)
    {
        if(arr[i] > max)
        max = arr[i];
    }
    return max;
}

void Swap(int *x , int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void countSort(int arr[] , int size)
{
    int i  , j , max , *countArray;
    max = FindMax(arr , size);
    countArray = (int *)malloc(sizeof(int) * (max + 1)); // the size of the max is 15 but i will increase one in it

    // Initialize the count array to 0
    for(int i = 0 ; i < max+1 ; i++)  // hna he did not print if i do not write this max+1
    {
        countArray[i] = 0;  //  Now i inizilte the elements in the new arr with 0...
    }

    // Count occurrences of each element
    for(int i = 0 ; i < size ; i ++)
    {
        countArray[arr[i]]++; // hna i will set the value of arr[i] in their index in countArray and if he duplicated i will increase the index in countArray
    }

    // Now i want to copy the elemnts in my array
    i = 0;  //  stand in  countArray
    j = 0; //   stand in  the main array
    while(i < max + 1) // hna el[i] will start from index 0 in the countArray
    {
        if(countArray[i] > 0)  // hna i will check if the index bigger then zero then i will copy it in the main arr
        {
            arr[j] = i;
            j++;
            countArray[i]--;
        }
        else
        {
            i++;
        }
    }

}



int main()
{

    int arr[] = {5, 3, 2, 6, 5, 9, 1, 7, 8, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    countSort(arr, size);

    printf("Sorted Array:   ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}