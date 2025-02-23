public class Solution {
    public int RomanToInt(string s) 
    {
        Dictionary<char, int> romanMap = new Dictionary<char, int>() {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},{'C', 100}, {'D', 500}, {'M', 1000}};
        int total  = 0 ;
        for(int i = 0 ; i < s.Length -1 ; i++)
        {
            int currectIndex = romanMap[s[i]];
            int NextIndex  = romanMap[s[i+1]];
            if(currectIndex >= NextIndex)
            total += currectIndex;
            else
            total -= currectIndex;
        }   
        total += romanMap[s[s.Length-1]]; 
        return total;
    }
}