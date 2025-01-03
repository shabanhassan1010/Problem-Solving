// Example 1:

// Input: nums = [12,345,2,6,7896]
// Output: 2
// Explanation: 
// 12 contains 2 digits (even number of digits). 
// 345 contains 3 digits (odd number of digits). 
// 2 contains 1 digit (odd number of digits). 
// 6 contains 1 digit (odd number of digits). 
// 7896 contains 4 digits (even number of digits). 
// Therefore only 12 and 7896 contain an even number of digits.

public class Solution 
{
    public int FindNumbers(int[] nums) 
    {
        int num = 0;
        for(int i = 0 ; i < nums.Length ; i++)
        {       
            int count = 0;  // must be in every index inizlate count with zero
            while(nums[i] != 0)
            {
                nums[i] = nums[i] / 10; 
                count++;
            }
            if(count % 2 == 0)
            num ++;
        }
        return num;
    }
}