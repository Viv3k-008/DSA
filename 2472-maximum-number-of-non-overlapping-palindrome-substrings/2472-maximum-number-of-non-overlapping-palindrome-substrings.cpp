class Solution {
public:
    void expand(int i, int j, string& s, vector<vector<bool>>& check){
        while(i >= 0 && j < s.size()){
            if(s[i] == s[j]){
                check[i][j] = true;
                i--,j++;
            }
            else break;
        }
    }
    vector<int> dp;
    int fn(int i, int k, int n, string& s, vector<vector<bool>>& check){
        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        int op1 = 0;
        for(int j = i+k-1; j < n ; j++){
            if(check[i][j]){
                op1 = max(op1, 1 + fn(j+1, k, n, s, check));
            }
        }

        int op2 = fn(i+1, k, n, s, check);
        return dp[i] = max(op1, op2);
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        dp.resize(n, -1);

        vector<vector<bool>> check(n, vector<bool>(n, false));
        for(int i = 0; i < n ; i++){
            if(i == n-1){
                expand(i, i, s, check);
            }
            else {
                expand(i, i, s, check);
                expand(i, i+1, s, check);
            }
        }
        return fn(0, k, n, s, check);
    }
};