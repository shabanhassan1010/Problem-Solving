using System;

public class Solution 
{
    public int MinimumChairs(string s) 
    {
        int e = 0; 
        int maxChairs = 0;
        for(int i = 0 ; i < s.length ; i++)
        {
            if(s[i] == 'E')
            {
                e++;         //  e = 1 | e = 1                        | e = 1                      | e = 2
                if(e > max)  //        | did? 1 > 1 = No so continue  | did? 1 > 1 = No so continue|did? 2 > 1 = yes 
                max = e;    // max = 1 | max still equal 1            | max still equal 1          | max = 2
            }
            else 
                e--;     // e = 0 |        | e = 0       | e = 1  
        }
        return maxChairs;
    }
}