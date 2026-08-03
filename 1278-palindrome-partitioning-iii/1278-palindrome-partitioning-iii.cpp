class Solution {
public:
    vector<vector<int>> dp;
    int check(int i, int j, string& s){
        int cnt = 0;
        while(i <= j){
            if(s[i] != s[j]){
                cnt++;
            }
            i++, j--;
        }

        return cnt;
    }
    int fn(int l, int n, string& s, int k){
        if(n-l == k) return 0;
        if(k == 0) return check(l, n-1, s);
        if(l >= n-1) return 1e9;

        if(dp[l][k] != -1) return dp[l][k];

        int mini = 1e9;
        for(int i = l; i < n-k ; i++){
            mini = min(check(l, i, s)+fn(i+1, n, s, k-1) , mini);
        }

        return dp[l][k] = mini;
    }
    int palindromePartition(string s, int k) {
        int n = s.size();

        dp.resize(n, vector<int>(k, -1));
        return fn(0, n, s, k-1);
    }
};