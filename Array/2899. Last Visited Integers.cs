public class Solution 
{
    public IList<int> LastVisitedIntegers(int[] nums) 
    {
        List<int> ans = new List<int>(); 
        List<int> seen = new List<int>();   
        int k = 0;                          

        foreach (int num in nums) // test case: [1,2,-1,-1,-1]
        {
            if (num != -1)       // 1 != -1 so added | 2 != -1 so added  | -1 != -1 false | -1 != -1 false  | -1 != -1 false 
            {
                seen.Add(num);  // seen[1]           | seen[1 , 2]       |
                k = 0;         
            }
            else
            {
                k++;                  //         1         |         2      |         3
                if (k <= seen.Count)  // if (1 <= 2) true  |  (2 <= 2) true |  if (3 <= 2) false 
                    ans.Add(seen[seen.Count - k]); 
                    // ans.add(seen(2-1))= 2  => ans.add(seenOfIndex[1]) = 2  =>     ans[2]  
                    // ans.add(seen(2-2))= 0  => ans.add(seenOfIndex[1]) = 2  =>     ans[2 , 1]    
                else
                    ans.Add(-1);  //  ans[ 2 , 1 , -1]
            }
        }
        return ans;
    }
}