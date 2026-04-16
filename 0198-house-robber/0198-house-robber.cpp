class Solution {
public:
    vector<int> dp;
    int fn(int i , vector<int>& nums){
        if(i >= nums.size()){
            return 0;
        }

        if(dp[i] != -1) return dp[i];

        int op1 = nums[i] + fn(i+2 , nums);
        int op2 = fn(i+1 , nums);

        return dp[i] = max(op1 , op2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        dp.assign(n , -1);
        
        return fn(0 , nums);
    }
};