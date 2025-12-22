class Solution {
public:
    vector<vector<int>> dp;
    int fn(int i , vector<int>& coins , int am){
        if(i >= coins.size()){
            if(am == 0){
                return 0;
            }
            return 1e9;
        }
        if(am == 0) return 0;
        else if(am < 0) return 1e9; 

        if(dp[i][am] != -1) return dp[i][am];

        int op1 = 1 + fn(i , coins , am-coins[i]);
        int op2 = fn(i+1 , coins , am);

        return dp[i][am] = min(op1 , op2);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.resize(n , vector<int>(amount+1 , -1));

        int ans = fn(0 , coins , amount);
        return (ans == 1e9)? -1 : ans;
    }
};