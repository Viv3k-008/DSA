class Solution {
public:
    vector<vector<vector<int>>> dp;
    int mod = 1e9+7;
    int fn(int n , int minProfit , vector<int>& group , vector<int>& profit , int actualProfit , int curProfit , int mens , int i , int m , vector<vector<vector<int>>>& dp){
        if(i == m){
            if(actualProfit >= minProfit && mens <= n){
                return 1;
            }
            return 0;
        }
        if(i > m || mens > n) return 0;

        if(dp[i][actualProfit][mens] != -1) return dp[i][actualProfit][mens];

        int op1 = fn(n , minProfit , group , profit , min(minProfit , curProfit+profit[i]) , curProfit+profit[i] , mens+group[i] , i+1 , m , dp);
        int op2 = fn(n , minProfit , group , profit , actualProfit , curProfit , mens , i+1 , m , dp);

        return dp[i][actualProfit][mens] = (op1+op2)%mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();

        dp.assign(m , vector<vector<int>>(101 , vector<int>(101 , -1)));
        return fn(n , minProfit , group , profit , 0 , 0 , 0 , 0 , m , dp);
    }
};