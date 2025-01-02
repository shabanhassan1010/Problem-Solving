#include <stdio.h>

// Global variable to replace the static variable in C#
int x = 0;

// Function to replace the static method in C#
int fun(int n)
{
    if (n > 0) // Corrected condition to avoid infinite recursion
    {
        x++; // Increment the global variable
        return fun(n - 1) + x; // Recursive call
    }
    return 0; // Base case
}

int main()
{
    int result = fun(5); // Call the function
    printf("%d\n", result); // Print the result
    return 0;
}