#include<stdio.h>
char* removeStars(char* s) 
{
    int size = strlen(s);
    char stack[size]; 
    int top = -1;     

    for (int i = 0; i < size; i++) 
    {
        if (s[i] == '*') 
        { 
            if (top >= 0)
                top--; // Pop the last character
        } 
        else
        {
            stack[++top] = s[i]; // Push the character
        }
    }
    stack[top + 1] = '\0'; // Null-terminate the string
    return strdup(stack);  // Return a dynamically allocated copy
}