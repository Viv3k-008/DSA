class Solution {
public:
    int fn(int i , int k , int n , vector<int>& prices , bool flag , vector<vector<vector<int>>>& dp){
        if(i >= n || k == 0){
            return 0;
        }

        if(k < 0) return -1e9;

        if(dp[i][k][flag] != -1) return dp[i][k][flag];

        int buy = 0;
        if(flag) buy = -prices[i] + fn(i+1 , k-1 , n , prices , false , dp);

        int sell = 0;
        if(!flag) sell = +prices[i] + fn(i+1 , k-1 , n , prices , true , dp);

        int skip = fn(i+1 , k , n , prices , flag , dp);

        return dp[i][k][flag] = max({buy , sell , skip});
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        k = 2*k;

        vector<vector<vector<int>>> dp(n , vector<vector<int>>(k+1 , vector<int>(2 , -1)));

        int ans = fn(0 , k , n , prices , true , dp);

        return ans == -1e9? 0 : ans;
    }
};