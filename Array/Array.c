using System;
using System.Linq;

class Program
{
    static void Main()
    {
        Console.WriteLine("Enter the size of the array:");
        int n = int.Parse(Console.ReadLine());

        int[] arr = new int[n];
        Console.WriteLine("Enter the elements of the array:");
        for (int i = 0; i < n; i++)
        {
            arr[i] = int.Parse(Console.ReadLine());
        }

        // Sort the array in descending order
        Array.Sort(arr);
        Array.Reverse(arr);

        // Initialize two sums for the two parts
        int sum1 = 0, sum2 = 0;

        // Distribute the elements to balance the sums
        foreach (int num in arr)
        {
            if (sum1 <= sum2)
            {
                sum1 += num;
            }
            else
            {
                sum2 += num;
            }
        }

        Console.WriteLine("Sum of first part: " + sum1);
        Console.WriteLine("Sum of second part: " + sum2);
    }
}
