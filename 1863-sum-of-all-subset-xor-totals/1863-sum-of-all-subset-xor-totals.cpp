class Solution {
public:
    vector<vector<int>> dp;
    int fn(int i , int xr , vector<int>& nums){
        if(i == nums.size()){
            return xr;
        }

        if(dp[i][xr] != -1) return dp[i][xr];
        int op1 = fn(i+1 , xr^nums[i] , nums);
        int op2 = fn(i+1 , xr , nums);

        return dp[i][xr] = op1+op2;
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n , vector<int>(32 , -1));
        return fn(0 , 0 , nums);
    }
};