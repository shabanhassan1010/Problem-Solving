public class Solution 
{
    public int MinEatingSpeed(int[] piles, int h) 
    {
        int Left = 1;  // I start eating from 1 beacause its not valid to start from zero.
        int right = piles.Max();
        if(h < piles.Length)     return -1;  // must be hours bigger then or equal piles[i]
        while(Left <= right)    // beacause i will started from Left
        {
            int mid = (Left + right) / 2;
            int totalHours = 0;
            int res = 0;
            for(int i = 0 ; i < piles.Length ; i++)
            {
                totalHours += (piles[i] + mid - 1) / mid; //   >>> 5 / 2 = 3 not 2
            }
            if(totalHours == h )  
                return mid;
            if(totalHours <= h )  
                right = mid - 1;    
            else
                Left = mid + 1; 
        }
        return Left;
    }
}