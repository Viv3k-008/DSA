class Solution {
public:
    vector<vector<int>> dp;
    int count(int i , int j , string& s , string& t){
        int n = s.size();
        int m = t.size();
        if(j == m){
            return 1;
        }
        else if(i == n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int op1 = 0 , op2 = 0;
        if(s[i] == t[j]){
            op1 = count(i+1 , j , s , t) + count(i+1 , j+1 , s , t);
        }
        else {
            op2 = count(i+1 , j , s , t);
        }
        return dp[i][j] = op1+op2;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        dp.resize(n+1 , vector<int>(m+1 , -1));
        return count(0 , 0 , s , t);
    }
};