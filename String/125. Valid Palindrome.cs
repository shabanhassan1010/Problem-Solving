using System.Text.RegularExpressions;

public class Solution {
    public bool IsPalindrome(string s) 
    {
        string cleaned = Regex.Replace(s, "[^a-zA-Z0-9]", "").ToLower();
        for(int i = 0 ; i < cleaned.Length ; i++)
        {
            if (cleaned[i] != cleaned[cleaned.Length - 1 - i]) // i use i so do not reapted steos more than one
            return false;
        }
        return true;
    }
}