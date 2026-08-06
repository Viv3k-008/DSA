class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1e9);

        dp[n-1] = 0;
        for(int i = n-1; i >= 0 ; i--){
            if(i == n-1) continue;

           for(int k = 1 ; k <= nums[i]; k++){
            dp[i] = min(dp[i], 1+dp[min(n-1,i+k)]);
           }

           dp[i] = min(dp[i], 1+dp[i+1]);
        }

        return dp[0];
    }
};