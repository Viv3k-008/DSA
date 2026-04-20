class Solution {
public:
    int fn(int i , int j , int n , int m , string& s , string& t , vector<vector<int>>& dp){
        if(j == m) return 1;
        if(i >= n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int op1 = 0;
        if(s[i] == t[j]){
            op1 = fn(i+1 , j+1 , n , m , s , t , dp);
        }
        int op2 = fn(i+1 , j , n , m , s , t , dp);

        return dp[i][j] = op1 + op2;
    }
    int numDistinct(string s, string t) {
        int n = s.size() , m = t.size();

        vector<vector<int>> dp(n , vector<int>(m , -1));
        return fn(0 , 0 , n , m , s , t , dp);
    }
};