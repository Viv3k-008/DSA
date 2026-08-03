class Solution {
public:
    vector<vector<int>> dp;
    int fn(int l, int r, vector<int>& nums){
        if(l > r) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        int op1 = nums[l] - fn(l+1, r, nums);
        int op2 = nums[r] - fn(l, r-1, nums);

        return dp[l][r] = max(op1, op2);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n-1;

       

        dp.resize(n, vector<int>(n, -1));
        int a = fn(l, r, nums);
       

        return a >= 0;
    }
};