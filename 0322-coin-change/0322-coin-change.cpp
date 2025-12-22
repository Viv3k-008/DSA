class Solution {
public:
    vector<vector<int>> dp;
    // int fn(int i , vector<int>& coins , int am){
    //     if(i >= coins.size()){
    //         if(am == 0){
    //             return 0;
    //         }
    //         return 1e9;
    //     }
    //     if(am == 0) return 0;
    //     else if(am < 0) return 1e9; 

    //     if(dp[i][am] != -1) return dp[i][am];

    //     int op1 = 1 + fn(i , coins , am-coins[i]);
    //     int op2 = fn(i+1 , coins , am);

    //     return dp[i][am] = min(op1 , op2);
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.resize(n+1 , vector<int>(amount+1 , 1e9));

        for(int i = 0 ; i <= n ; i++){
            dp[i][0] = 0;
        }

        for(int i = n-1 ; i >= 0 ; i--){
            for(int am = 1 ; am <= amount; am++){
                
                int op1 = 1e9;
                if(coins[i] <= am) op1 = 1 + dp[i][am-coins[i]];
                
                int op2 = dp[i+1][am];

                dp[i][am] = min(op1 , op2);
            }
        }

        int ans = dp[0][amount];
        return (ans == 1e9)? -1 : ans;

    }
};