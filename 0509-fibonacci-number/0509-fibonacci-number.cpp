class Solution {
public:
    vector<int> dp;
    int fn(int n){
        if(n == 0 || n == 1){
            return n;
        }
        if(dp[n] != -1) return dp[n];

        return dp[n] = fn(n-1) + fn(n-2);
    }
    int fib(int n) {
        if(n == 1 || n == 0) return n;
        dp.resize(n+1 , -1);
        return fn(n);
    }
};