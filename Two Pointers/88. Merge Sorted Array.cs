public class Solution {
    public void Merge(int[] nums1, int m, int[] nums2, int n) 
    {
        int i = 0 , j = 0 , k = 0;
        int [] NewArr = new int[ m + n];
        while (i < m && j < n)
        {
            if(nums1[i] < nums2[j])
            NewArr[k++] = nums1[i++];
            else
            NewArr[k++] = nums2[j++];
        }
        while(i < m)
        {
            NewArr[k++] = nums1[i++];
        }
        while(j < n)
        {
            NewArr[k++] = nums2[j++];
        }
            Array.Copy(NewArr, nums1, NewArr.Length);
    }
}