class Solution {
public:
    bool fn(int i , int j , string& s , string& p , vector<vector<int>>& dp){
        if(j == p.size()){
            return i == s.size();
        }

        // we are not checking i == s.size() , coz rest of p elements after j index can be zero due to "*" . As we can get answer with the notTake part
        
        if(dp[i][j] != -1) return dp[i][j];

        bool take = false , notTake = false , firstCharMatch = false;

        if(i < s.size() && (s[i] == p[j] || p[j] == '.')){
            firstCharMatch = true;
        }

        if(j+1 < p.size() && p[j+1] == '*'){
            take = firstCharMatch && fn(i+1 , j , s , p , dp);
            notTake = fn(i , j+2 , s , p , dp);

            return dp[i][j] = take || notTake;
        }

        return dp[i][j] = firstCharMatch && fn(i+1 , j+1 , s , p , dp);
    }
    bool isMatch(string s, string p) {
        
        int n = s.size() , m = p.size();

        vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));
        return fn(0 , 0 , s , p , dp);
    }
};