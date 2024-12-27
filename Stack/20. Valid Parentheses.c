#include<stdio.h>
#include <stdbool.h> // Include for true and false


bool isValid(char *s) 
{
    struct Stack *st = NULL; 

    for (int i = 0; s[i] != '\0'; i++) 
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') 
            Push(&st, s[i]);
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']') 
        {
            if (isEmpty(st)) 
                return false;
            char top = Pop(&st);
            if (!isMatchingPair(top, s[i])) 
                return false;
        }
    }
    return isEmpty(st);
}