class Solution {
public:
    vector<vector<int>> dp;
    int fn(int l, int r, int n, vector<int>& nums){
        if(r-l+1 < 3) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        int cost = 1e9;
        for(int i = l+1; i < r; i++){
            int cur = nums[l]*nums[i]*nums[r];

            cost = min(cost, cur + fn(l, i, n, nums) + fn(i, r, n, nums));
        }

        return dp[l][r] = cost;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();

        dp.resize(n, vector<int>(n, -1));
        return fn(0, n-1, n, values);
    }
};