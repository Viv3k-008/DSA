class Solution {
public:
    
    bool fn(int i , vector<int>& nums , int sum , vector<vector<int>>& dp){
        if(i >= nums.size()){
            if(sum == 0) return 1;
            else return 0;
        }

        if(sum == 0) return 1;
        if(dp[i][sum] != -1) return dp[i][sum];

        int op1 = 0;
        if(nums[i] <= sum) op1 = fn(i+1 , nums , sum-nums[i] , dp);
        int op2 = fn(i+1 , nums , sum , dp);

        return dp[i][sum] = op1 || op2;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int total = 0;
        for(int i : nums) total += i;

        if(total%2) return false;

        vector<vector<int>> dp(n , vector<int>(total/2+1 , -1));

        return fn(0 , nums , total/2 , dp);
    }
};