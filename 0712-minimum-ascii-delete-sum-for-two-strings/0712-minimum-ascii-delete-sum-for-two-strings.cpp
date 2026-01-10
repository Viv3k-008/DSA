class Solution {
public:
    vector<vector<int>> dp;
    int fn(int i , int j , string& s1 , string& s2){
        if(i >= s1.size() || j >= s2.size()){
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]){
            return (int) s1[i] + fn(i+1 , j+1 , s1 , s2);
        }

        int op1 = fn(i+1 , j , s1 , s2);
        int op2 = fn(i , j+1 , s1 , s2);

        return dp[i][j] = max(op1 , op2);
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size() , m = s2.size();
        dp.resize(n , vector<int>(m , -1));
        int total = 0;

        for(char i : s1){
            total += i;
        }
        for(char i : s2){
            total += i;
        }

        int common = fn(0 , 0 , s1 , s2);
        cout<<common;
        return total - 2*common;
    }
};