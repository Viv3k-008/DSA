class Solution {
public:
    static bool comp(string& a, string& b){
        return a.size() < b.size();
    }
    int check(string &s1, string &s2){
        int n = s1.size(), m = s2.size();

        int i = 0, j = 0;
        while(i < n && j < m){
            if(s1[i] == s2[j]){
                i++, j++;
            }
            else j++;
        }

        return i == n;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), comp);

        vector<int> dp(n, 1);
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i-1; j >= 0 ; j--){
                int l = words[i].size(), m = words[j].size();
                if(l-m == 1){
                    if(check(words[j], words[i]) &&( dp[j]+1 > dp[i])){
                        dp[i] = dp[j]+1;
                    }
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};