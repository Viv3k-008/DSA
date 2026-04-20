class Solution {
public:
    vector<int> dp;
    int fn(int i , int n){
        if(i == n){
            return 1;
        }
        if(i > n) return 0;

        if(dp[i] != -1) return dp[i];

        int op1 = fn(i+1 , n);
        int op2 = fn(i+2 , n);

        return dp[i] = op1 + op2;
    }
    int climbStairs(int n) {
        dp.assign(n , -1);
        return fn(0 , n);
    }
};