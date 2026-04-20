class Solution {
public:
    int fn(int i , int target , vector<int>& nums , int n ,vector<vector<int>>& dp){
        if(i >= n){
            if(target == 0){
                return 1;
            }
            else return 0;
        }
        if(target < 0) return 0;

        if(dp[i][target] != -1) return dp[i][target];

        int op1 = fn(i+1 , target-nums[i] , nums , n , dp);
        int op2 = fn(i+1 , target , nums , n , dp);

        return dp[i][target] = op1 + op2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size() , total = 0;

        for(int i : nums) total += i;
        if((total+target)%2) return 0;
        if(total < abs(target)) return 0;
        int newTarget = (total+target)/2;
        vector<vector<int>> dp(n , vector<int>(newTarget+1 , -1));

        return fn(0 , newTarget , nums , n , dp);
    }
};