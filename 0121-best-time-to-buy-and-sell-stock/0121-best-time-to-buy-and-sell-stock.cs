public class Solution {
    public int MaxProfit(int[] prices) {
        int n = prices.Length;
        // [7,1,5,3,6,4]   
        int ans = 0;
        int mini = prices[0];

        for(int i = 0 ; i < n ; i++){
            ans = Math.Max(ans, prices[i]-mini); // 4, 5 
            mini = Math.Min(mini, prices[i]);
        }

        return ans;
    }
}