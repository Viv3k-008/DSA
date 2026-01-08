class Solution {
public:
    // int fn(int i , vector<int>& nums , int prev , vector<vector<int>>& dp){
    //     if(i == nums.size()){
    //         return 0;
    //     }

    //     if(dp[i][prev+1] != -1) return dp[i][prev+1];

    //     int op1 = 0;
    //     if(prev == -1 || nums[i] > nums[prev]) op1 = fn(i+1 , nums , i , dp) + 1;
    //     int op2 = fn(i+1 , nums , prev , dp);

    //     return dp[i][prev+1] = max(op1 , op2);
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();

    //     vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));
        
    //     for(int i = n-1 ; i >= 0 ; i--){
    //         for(int prev = i-1 ; prev >= -1 ; prev--){
    //             if(prev == -1 || nums[i] > nums[prev+1]){
    //                 dp[i][prev+1] = max(1+dp[i+1][i+1] , dp[i+1][prev+1]);
    //             }
    //             else dp[i][prev+1] = dp[i+1][prev+1];
    //         }
    //     }

    //     return dp[0][0];
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n,1);
        int maxi = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            for(int prev = i-1 ; prev >= 0 ; prev--){
                if(nums[i] > nums[prev]){
                    if(dp[prev]+1 > dp[i]){
                        dp[i] = dp[prev]+1;
                    }
                }
            }
            maxi = max(maxi , dp[i]);
        }

        return maxi;
    }
};