class Solution {
public:
    
    vector<vector<int>> dp;
    int fn(int i , int amount , vector<int>& coins){
        if(i == coins.size()-1){
            if(amount%coins[i] == 0){
                return amount/coins[i];
            }
            else return 1e9;
        }

        if(amount == 0) return 0;
        else if(amount < 0) return INT_MAX;

        if(dp[i][amount] != -1) return dp[i][amount];

        int op1 = 1e9;
        if(coins[i] <= amount) op1 = 1 + fn(i , amount-coins[i] , coins);
        int op2 = fn(i+1 , amount , coins);

        return dp[i][amount] = min(op1 , op2);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        dp.assign(n , vector<int>(amount+1 , -1));
        
        int ans = fn(0 , amount , coins);

        return ans >= 1e9? -1 : ans;
    }
};