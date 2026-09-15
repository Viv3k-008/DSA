class Solution {
public:
    bool check(int i, int j, string& s){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++, j--;
        }
        return true;
    }
    vector<int> dp;
    int fn(int i, int k, int n, string& s){
        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        int op1 = 0;
        for(int j = i+k-1; j < n ; j++){
            if(j-i+1 >= k && check(i, j, s)){
                op1 = max(op1, 1 + fn(j+1, k, n, s));
            }
        }

        int op2 = fn(i+1, k, n, s);
        return dp[i] = max(op1, op2);
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        dp.resize(n, -1);
        return fn(0, k, n, s);
    }
};