class Solution {
public:
    vector<vector<int>> dp;
    int fn(int i, int n, vector<int>& p, bool buy){
        if(i >= n){
            if(buy) return 0;
            else return -1e9;
        }

        if(dp[i][buy] != -1) return dp[i][buy];
        int op = -1e9;
        if(buy){
            op = fn(i+1, n, p, false) - p[i];
        }
        else{
            op = fn(i+1, n, p, true) + p[i];
        }

        int skip = fn(i+1, n, p, buy);

        return dp[i][buy] = max(op, skip);

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        dp.resize(n, vector<int>(2, -1));
        return fn(0, n, prices, true);
    }
};