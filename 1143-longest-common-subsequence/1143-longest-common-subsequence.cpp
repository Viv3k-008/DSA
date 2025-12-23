class Solution {
public:
    int fn(string& t1 , string& t2 , int i , int j , vector<vector<int>>& dp){
        if(i == t1.size() || j == t2.size()){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(t1[i] == t2[j]){
            return dp[i][j] = 1 + fn(t1 , t2 , i+1 , j+1 , dp);
        }

        int op1 = fn(t1 , t2 , i+1 , j , dp);
        int op2 = fn(t1 , t2 , i , j+1 , dp);

        return dp[i][j] = max(op1 , op2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size() , m = text2.size();

        vector<vector<int>> dp(n , vector<int>(m , -1));
        int ans = fn(text1 , text2 , 0 , 0 , dp);

        return (ans == -1e9)? 0 : ans;
    }
};