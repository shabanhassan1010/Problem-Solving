public class Solution {
    public string RestoreString(string s, int[] indices) 
    {
        // deivide s , indices into 2
        char [] res = new char[s.Length];
        for(int i = 0 ; i < s.Length ; i++)
        {
            res[indices[i]] = s[i];
        } 
        return new string(res);  
    }
}