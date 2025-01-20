using System;
public class Solution {
    public int RemoveDuplicates(int[] nums){
        int uniqueIndex = 0;
        for (int i = 1; i < nums.Length; i++)
        {
            if (nums[i] != nums[uniqueIndex])
            {
                uniqueIndex++;
                nums[uniqueIndex] = nums[i];
            }
        }
        return uniqueIndex + 1;
    }
}