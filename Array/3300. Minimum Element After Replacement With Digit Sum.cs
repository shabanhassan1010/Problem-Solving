//Test Case : [10,12,13,14]
public class Solution 
{
    public int MinElement(int[] nums) 
    {
        int sum = 0 ;
        for(int i = 0 ; i < nums.Lenght ; i++) // index[0]
        {
            while(nums[i] != 0)
            {
                sum += nums[i] % 10;              // add the last digit of nums[i] in the sum    >> 10 % 10 , add 0 into sum  >> 1 % 10  add 1 into sum 1 + 0 = 1 now nums[i] = 0 so i wil move int0 the next index
                nums[i] = nums[i] / 10;           // remove the last digit from nums[i]          >> remove 0 from 10          >> remove 1 from 10
            }
            nums[i] = sum;
        }
        nums = sum;
        Array.Sort(nums);
        return nums[0];
    }
}