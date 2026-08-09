class Solution {
public:
    vector<vector<int>> dp;
    int fn(int i, vector<int>& piles, int n, int m){
        if(i == n) return 0;

        if(dp[i][m] != -1) return dp[i][m];

        int sum = 0, ans = INT_MIN;
        for(int k = i; (k < i+2*m) && (k < n) ; k++){
            sum += piles[k];

            int x = k-i+1;
            ans = max(ans, sum - fn(k+1, piles, n, max(m, x)));
        }

        return dp[i][m] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        dp.resize(n, vector<int>(2*n+1, -1));
        
        int total = accumulate(piles.begin(), piles.end(), 0);
        int diff = fn(0, piles, n, 1);
        return (total+diff)/2;
    }
};