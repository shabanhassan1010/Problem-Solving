#include <stdio.h>
#include <stdlib.h>

// Merging Two List in single list....
void MarggingTwoList(int arr1[] , int arr2[] , int arr3[] , int sizeForArr1 , int sizeForArr2)
{
        int i = 0, j = 0, k = 0;
    while(i < sizeForArr1 && j < sizeForArr2)
    {
        if(arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            arr3[k] = arr1[j];
            j++;
            k++;
        }
    }
    while(i < sizeForArr1)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    while(j < sizeForArr2)
    {
        arr3[k] = arr1[j];
        j++;
        k++;
    }
}


// Merging Two List in single list....
void Mergging(int arr1[] , int left , int mid , int right)
{

    int i = left;
    int k = left;
    int j = mid + 1;
    int arr2 [20];
    while(i <= mid && j <= right)
    {
        if(arr1[i] < arr1[j])
        {
            arr2[k++] = arr1[i++];
        }
        else
        {
            arr2[k++] = arr1[j++];
        }
    }
    while(i <= mid)
    {
        arr2[k] = arr1[i];
        k++;
    }
    while(j <= left )
    {
        arr2[k] = arr1[j];
        k++;
    }
    for(int i = 0 ; i <= right ; i++)
    {
        arr1[i] = arr2[i];
    }
}

int main()
{
    int arr[] = {1 , 5 , 7 ,2 ,10 , 9};
    int n1 = 6;
    int arr2[] = {4 , 10 , 6 ,2 ,11 , 9};
    int n2 = 6;
    int arr3[n1 + n2];
    MarggingTwoList(arr , arr2 , arr3 , n1 , n2 );
    for(int i = 0 ; i < n1 + n2 ; i++)
    {
        printf("%d" , arr3[i]);
            printf("\n");
    }

    return 0;
}









