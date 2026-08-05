class Solution {
public:
    int cnt(int l, int r, string& s){
        int c = 0;

        while(l <= r){
            if(s[l] != s[r]){
                c++;
            }
            l++, r--;
        }

        return c;
    }
    vector<vector<int>> dp;
    int fn(int l, int n, int k, string& s){
        if(n-l == k) return 0;
        if(k == 0) return cnt(l, n-1, s);
        if(l >= n-1) return 1e9;


        if(dp[l][k] != -1) return dp[l][k];

        int mini = INT_MAX;
        for(int i = l; i < n-k; i++){
            mini = min(mini, cnt(l,i,s) + fn(i+1, n, k-1, s));
        }

        return dp[l][k] = mini;
    }
    int palindromePartition(string s, int k) {
        int n = s.size();

        dp.resize(n,vector<int>(k, -1));
        return fn(0, n, k-1, s);
    }
};