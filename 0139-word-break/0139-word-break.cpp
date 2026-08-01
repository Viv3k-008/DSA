class Solution {
public:
    int dp[300];
    bool fn(int l, int n, string& s, unordered_map<string,int>& mp){
        if(l == n) return true;

        string str = "";

        if(dp[l] != -1) return dp[l];
        
        for(int i = l ; i < n ; i++){
            str += s[i];
            
            if(mp.count(str) && fn(i+1, n, s, mp)){
                return dp[l] = true;
            }
        }
        return dp[l] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        memset(dp, -1, 300);

        unordered_map<string,int> mp;
        for(int i = 0 ; i < wordDict.size() ; i++){
            mp[wordDict[i]]++;
        }

        return fn(0, n, s, mp);
    }
};