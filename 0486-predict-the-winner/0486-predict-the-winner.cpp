class Solution {
public:
    vector<vector<int>> dp;
    int fn(int l, int r, vector<int>& nums){
        if(l > r) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        int op1 = nums[l] + min(fn(l+2, r, nums) , fn(l+1, r-1, nums));    // Taking min here because the opponent will also get chance and he will also take the max one so the left will be the min one that you can take for the player A.
        int op2 = nums[r] + min(fn(l+1, r-1, nums) , fn(l, r-2, nums));

        return dp[l][r] = max(op1, op2);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n-1;

        int total = 0;
        for(int i : nums) total += i;

        dp.resize(n, vector<int>(n, -1));
        int a = fn(l, r, nums);
        int b = total - a;

        return a >= b;
    }
};