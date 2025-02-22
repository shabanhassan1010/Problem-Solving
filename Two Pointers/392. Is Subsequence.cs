public class Solution {
    public bool IsSubsequence(string s, string t)
    {
        int i = 0;
        int j = 0;
        while(i < s.Length && j < t.Length)
        {
            if(s[i] == t[j])
            {
              i++;  
            }
            j++;
        }
        // Return true if all characters in s were found in t, false otherwise.
        return i == s.Length;  // s.Length -> المقصود بيها هل الحروف اللي في الكلمه التانبه طلعت مساويه للحروف في الكلمه الاولي ولا لا 
    }
}