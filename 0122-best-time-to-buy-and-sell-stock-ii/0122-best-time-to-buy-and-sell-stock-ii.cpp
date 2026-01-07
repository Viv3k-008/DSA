class Solution {
public:
    vector<vector<int>> dp;
    int fn(int i , int n , vector<int>& prices , int flag){
        if(i == n){
            return 0;
        }

        if(dp[i][flag] != -1) return dp[i][flag];

        int op1 = 0 , op2 = 0;
        if(flag){
            op1 = -prices[i] + fn(i+1 , n , prices , 0);
        }
        else op1 = prices[i] + fn(i+1 , n , prices , 1);

        op2 = fn(i+1 , n , prices , flag);

        return dp[i][flag] = max(op1 , op2);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n , vector<int>(2 , -1));
        return fn(0 , n , prices , 1);
    }
};