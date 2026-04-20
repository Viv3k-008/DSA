class Solution {
public:
    vector<int> dp;
    int fn(int i , int n , vector<int>& cost){
        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        int op1 = 1e9 , op2 = 1e9;
        if(i+1 <= n) op1 = cost[i] + fn(i+1 , n , cost);
        if(i+2 <= n) op2 = cost[i] + fn(i+2 , n , cost);

        return dp[i] = min(op1 , op2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.assign(n , -1);
        int ans1 = fn(0 , n , cost);
        dp.assign(n , -1);
        int ans2 = fn(1 , n , cost);

        return min(ans1 , ans2);
    }
};