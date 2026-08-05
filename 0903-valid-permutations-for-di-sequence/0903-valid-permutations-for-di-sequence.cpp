class Solution {
public:
    int MOD = 1e9+7;
    vector<vector<int>> dp;
    int fn(int i, int j, string &s){
        if(i == 0) return 1;

        char c = s[i-1];

        if(dp[i][j] != -1) return dp[i][j];

        int op = 0;
        if(c == 'I'){
            for(int k = 0; k < j; k++){
                op = (op + fn(i-1, k, s))%MOD;
            }
        }
        else {
            for(int k = j; k < i; k++){
                op = (op + fn(i-1, k, s))%MOD;
            }
        }

        return dp[i][j] = op;
    }
    int numPermsDISequence(string s) {
        int n = s.size();
        long long ans = 0;

        dp.resize(n+1, vector<int>(n+1, -1));
        
        for (int j = 0; j <= n; j++) {
            ans = (ans + fn(n, j, s)) % MOD;
        }
        return (int) ans;
    }
};