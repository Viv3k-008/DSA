class Solution {
public:
    vector<vector<int>> dp;
    int fn(int l, int r, int sum, vector<int>& nums){
        if(l > r) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        int op1 = (sum-nums[l]) - fn(l+1, r, sum-nums[l], nums);
        int op2 = (sum-nums[r]) - fn(l, r-1, sum-nums[r], nums);

        return dp[l][r] = max(op1, op2); 
    }
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();

        int sum = 0;
        for(int i : stones) sum += i;

        dp.resize(n, vector<int>(n, -1));
        return fn(0, n-1, sum, stones);
    }
};