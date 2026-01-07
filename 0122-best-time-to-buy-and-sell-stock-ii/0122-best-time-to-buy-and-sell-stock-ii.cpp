class Solution {
public:
    vector<vector<int>> dp;
    // int fn(int i , int n , vector<int>& prices , int flag){
    //     if(i == n){
    //         return 0;
    //     }

    //     if(dp[i][flag] != -1) return dp[i][flag];

    //     int op1 = 0 , op2 = 0;
    //     if(flag){
    //         op1 = -prices[i] + fn(i+1 , n , prices , 0);
    //     }
    //     else op1 = prices[i] + fn(i+1 , n , prices , 1);

    //     op2 = fn(i+1 , n , prices , flag);

    //     return dp[i][flag] = max(op1 , op2);
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n+1 , vector<int>(2 , 0));
        // return fn(0 , n , prices , 1);

        for(int i = n-1 ; i >= 0 ; i--){
            
            for(int flag = 0 ; flag < 2 ; flag++){
                int op1 = 0 , op2 = 0;
                if(flag){
                    op1 = max(-prices[i]+dp[i+1][0] , dp[i+1][1]);
                }
                else op1 = max(prices[i]+dp[i+1][1] , dp[i+1][0]);

                op2 = dp[i+1][flag];

                dp[i][flag] = max(op1 , op2);
            }
        }

        return dp[0][1];
    }
};