using System;

public class Solution {
    public int LengthOfLastWord(string s) 
    {
        int count = 0 ;
        int theEndOfString = s.Length-1;
        while(theEndOfString >= 0 && s[theEndOfString] == ' ')
        theEndOfString --;
        while(theEndOfString >= 0 && s[theEndOfString] != ' ')
        {
            count ++;
            theEndOfString--;  // if i do not write this line it will be infinite loop 
        }
        return count;
    }
}