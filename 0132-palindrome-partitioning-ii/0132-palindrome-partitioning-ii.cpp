class Solution {
public:
    bool check(int l, int r, string& s){
        while(l <= r){
            if(s[l++] != s[r--]){
                return false;
            }
        }
        return true;
    }

    vector<int> dp;
    int fn(int i, int n, string& s){
        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        int cuts = 1e9;
        for(int k = i; k < n ; k++){
            if(check(i, k, s)){
                cuts = min(cuts, 1 + fn(k+1, n, s));
            }
        }

        return dp[i] = cuts;
    }
    int minCut(string s) {
        int n = s.size();

        dp.resize(n, -1);

        return fn(0, n, s)-1;
    }
};