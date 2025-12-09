class Solution {
public:
    int fn(int i , vector<int>& nums , vector<int>& dp){
        if(i >= nums.size()){
            return 0;
        }
        if(dp[i] != -1) return dp[i];

        int op1 = fn(i+2 , nums , dp) + nums[i];

        int op2 = fn(i+1 , nums , dp);

        return dp[i] = max(op1 , op2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , -1);
        return fn(0 , nums , dp);
    }
};