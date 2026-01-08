class Solution {
public:
    int fn(int i , vector<int>& nums , int prev , vector<vector<int>>& dp){
        if(i == nums.size()){
            return 0;
        }

        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        int op1 = 0;
        if(prev == -1 || nums[i] > nums[prev]) op1 = fn(i+1 , nums , i , dp) + 1;
        int op2 = fn(i+1 , nums , prev , dp);

        return dp[i][prev+1] = max(op1 , op2);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n , vector<int>(n+1 , -1));
        return fn(0 , nums , -1 , dp);
    }
};