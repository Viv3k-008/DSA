class Solution {
public:
    vector<vector<vector<int>>> dp;
    int mod = 1e9+7;
    int fn(int m , int n , int maxMove , int i , int j , int move){
        if(i >= m || j >= n || i < 0 || j < 0){
            if(move <= maxMove){
                return 1;
            }
            return 0;
        }

        if(move > maxMove) return 0;

        if(dp[i][j][move] != -1) return dp[i][j][move];

        int op1 = fn(m , n , maxMove , i+1 , j , move+1);
        int op2 = fn(m , n , maxMove , i , j+1 , move+1);
        int op3 = fn(m , n , maxMove , i-1 , j , move+1);
        int op4 = fn(m , n , maxMove , i , j-1 , move+1);

        return dp[i][j][move] = (((((op1+op2)%mod)+op3)%mod)+op4)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp.assign(m , vector<vector<int>>(n , vector<int>(51 , -1)));

        return fn(m , n , maxMove , startRow , startColumn , 0);
    }
};