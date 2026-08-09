class Solution {
public:
    vector<vector<int>> dp;
    int fn(int i, int j, int n, int m, string& s, string& p){
        if(i == n && j < m){
            while(j < m){
                if(p[j] != '*') return false;
                j++;
            }
            return true;
        }
        if(i == n && j == m) return true;
        if(i < n && j == m) return false;


        if(dp[i][j] != -1) return dp[i][j];


        if(s[i] == p[j] || p[j] == '?') return fn(i+1, j+1, n, m , s, p);
        else if(p[j] == '*'){
            return dp[i][j] = fn(i+1, j, n , m , s, p) || fn(i, j+1, n, m , s, p);
        }
        else return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();

        dp.resize(n, vector<int>(m, -1));
        return fn(0, 0, n, m, s, p);
    }
};