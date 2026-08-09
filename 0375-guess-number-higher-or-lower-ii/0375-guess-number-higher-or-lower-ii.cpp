class Solution {
public:
    vector<vector<int>> dp;
    int fn(int l, int r){
        if(l >= r) return 0;

        if(dp[l][r] != -1) return dp[l][r];
        int cur = INT_MAX;
        for(int k = l; k <= r; k++){
            cur = min(cur, k+max(fn(l, k-1), fn(k+1, r)));
        }

        return dp[l][r] = cur;
    }
    int getMoneyAmount(int n) {
        dp.resize(n+1, vector<int>(n+1, -1));
        return fn(1, n);
    }
};