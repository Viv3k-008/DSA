class Solution {
public:
    int cnt = 0;
    vector<int> dp;
    int fn(int i , string& s){
        if(i == s.size()){
            return 1;
        }
        else if(s[i] == '0'){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
       
        int op1 = fn(i+1 , s);
        int op2 = 0;
        if(i+1 < s.size()){
            string temp = "";
            temp += s[i];
            temp += s[i+1];

            int num = stoi(temp);
            if(num <= 26){
                op2 = fn(i+2 , s);
            }
        }

        return dp[i] = op1+op2;
    }
    int numDecodings(string s) {
        dp.resize(s.size(),-1);
        return fn(0 , s);
    }
};