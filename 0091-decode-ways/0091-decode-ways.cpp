class Solution {
public:
    vector<int> dp;
    int fn(int i, int n, string& s){
        if(i == n) return 1;
       
        int num1 = s[i]-'0';
        int num2 = 27;
        if(i < n-1) num2 = (s[i]-'0')*10 + (s[i+1]-'0');
        
        if(dp[i] != -1) return dp[i];

        int op1 = 0, op2 = 0;
        if(0 < num1){
            op1 = fn(i+1, n, s);
        }
        if(10 <= num2 && num2 <= 26){
            op2 = fn(i+2, n, s);
        }
      

        return dp[i] = op1 + op2;
    }
    int numDecodings(string s) {
        int n = s.size();

        dp.resize(n, -1);
        return fn(0, n, s);
    }
};