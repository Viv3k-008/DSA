class Solution {
public:
    int MOD = 1e9+7;
    vector<vector<vector<int>>> dp;
    int fn(int i, int n, int k , bool st){
        if(i == n && k == 0 && !st) return 1;
        if(i >= n) return 0;

        if(k < 0) return 0;

        if(dp[i][k][st] != -1) return dp[i][k][st];

        int Fcut = (st == false)? fn(i+1, n, k, true) : 0;
        int Scut = (st == true)? fn(i+1, n, k-1, false) + fn(i+1, n, k-1, true): 0;
        int skip = fn(i+1, n, k, st);

        return dp[i][k][st] = ((Fcut+Scut)%MOD+skip)%MOD;
    }
    int numberOfSets(int n, int k) {
        dp.resize(n+1, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return fn(0, n, k, false);
    }
};