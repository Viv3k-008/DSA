class Solution {
public:
    int fn(int l, int r, string& s, vector<vector<int>>& dp){
       if(l > r) return 0;
       if(l == r) return 1;

       if(dp[l][r] != -1) return dp[l][r];

       int op1 = 1 + fn(l+1, r, s, dp);
       int op2 = INT_MAX;
       for(int k = l+1 ; k <= r; k++){
          if(s[l] == s[k]){
             op2 = min(op2, fn(l+1, k-1, s, dp) + fn(k, r, s, dp));
          }
       }

       return dp[l][r] = min(op1, op2);
    }
    int strangePrinter(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        return fn(0, n-1, s, dp);
    }
};