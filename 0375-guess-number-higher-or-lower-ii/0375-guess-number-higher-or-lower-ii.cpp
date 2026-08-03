class Solution {
public:
    int fn(int l, int r, vector<vector<int>>& dp){
        if(l >= r) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        int mini = 1e9;
        for(int k = l; k <= r; k++){
            mini = min(k + max(fn(l, k-1, dp), fn(k+1, r, dp)), mini);
        }

        return dp[l][r] = mini;
    }
    int getMoneyAmount(int n) {

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return fn(1, n, dp);
    }
};