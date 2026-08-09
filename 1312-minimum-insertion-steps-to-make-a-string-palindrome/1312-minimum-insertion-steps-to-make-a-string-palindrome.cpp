class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(),s2.end());

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i = n-1; i >= 0 ; i--){
            for(int j = n-1 ; j >= 0 ; j--){
                if(s[i] == s2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else {
                    dp[i][j] = max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }

        return n - dp[0][0];
    }
};