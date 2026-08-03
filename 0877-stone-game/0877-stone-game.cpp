class Solution {
public:
    vector<vector<int>> dp;
    int fn(int l, int r, vector<int>& piles){
        if(l > r){
            return 0;
        }

        if(dp[l][r] != -1) return dp[l][r];
        int left = piles[l] - fn(l+1, r, piles);
        int right = piles[r] - fn(l, r-1, piles);

        return dp[l][r] = max(left, right);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.resize(n, vector<int>(n, -1));
        return fn(0, n-1, piles);
    }
};