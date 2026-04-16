class Solution {
public:
    int fn(int i , int j , int n , int m , string &word1 , string &word2 , vector<vector<int>>& dp){
        if(i == n) return m-j;
        if(j == m) return n-i;

        if(word1[i] == word2[j]){
            return dp[i][j] = fn(i+1 , j+1 , n , m , word1 , word2 , dp);
        }

        if(dp[i][j] != -1) return dp[i][j];

        // insert
        int op1 = 1 + fn(i , j+1 , n , m , word1 , word2 , dp);

        // delete
        int op2 = 1 + fn(i+1 , j , n , m , word1 , word2 , dp);

        // replace
        int op3 = 1 + fn(i+1 , j+1 , n , m , word1 , word2 , dp);


        return dp[i][j] = min({op1 , op2 , op3});
    }
    int minDistance(string word1, string word2) {
        int n = word1.size() , m = word2.size();

        vector<vector<int>> dp(n , vector<int>(m , -1));

        return fn(0 , 0 , n , m , word1 , word2 , dp);
    }
};