class Solution {
public:
    bool check(int i , int j , string& s){
        while(i < j){
            if(s[i++] != s[j--]){
                return false;
            }
        }

        return true;
    }
    int fn(int i , int n , string& s , vector<int>& dp){
        if(i == n) return 0;
        
        if(dp[i] != -1) return dp[i];

        int mini = INT_MAX;
        for(int k = i ; k < n ; k++){
            int cur = INT_MAX;
            if(check(i , k , s)){
                cur = 1 + fn(k+1 , n , s , dp);
            }

            mini = min(mini , cur);
        }

        return dp[i] = mini;
    }
    int minCut(string s) {
        int n = s.size();

        if(n == 1) return 0;

        vector<int> dp(n , -1);

        return fn(0 , n , s , dp)-1;
    }
};