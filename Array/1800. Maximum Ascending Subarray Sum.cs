public class Solution 
{
    public int MaxAscendingSum(int[] nums)
    {

        int MaxSize = nums[0];
        int CurrrentNumber = nums[0];
        for(int i = 1; i < nums.Length; i++)
        {
                if (nums[i] > nums[i - 1])
                    CurrrentNumber += nums[i];
                else
                    CurrrentNumber = nums[i];
                if (CurrrentNumber > MaxSize)
                    MaxSize = CurrrentNumber;
        }
            
            return MaxSize;
    }
} 