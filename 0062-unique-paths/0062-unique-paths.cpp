class Solution {
public:
    int fn(int i , int j , int m , int n , vector<vector<int>>& dp){
        if(i == m-1 && j == n-1) return 1;
        if(i < 0 || i >= m || j < 0 || j >= n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int op1 = fn(i+1 , j , m , n , dp);
        int op2 = fn(i , j+1 , m , n , dp);

        return dp[i][j] = op1 + op2;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n , -1));

        return fn(0 , 0 , m , n , dp);   
    }
};