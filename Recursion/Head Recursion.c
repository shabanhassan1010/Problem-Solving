#include <stdio.h>
#include <stdlib.h>


void fun(int n)
{
    if(n > 0)
    {
        fun(n-1);
        printf("%d" , n);
    }
}

int main()
{
    int n = 3;
    fun(n);
}
