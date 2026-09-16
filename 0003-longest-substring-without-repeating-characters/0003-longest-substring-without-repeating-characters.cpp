class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        unordered_map<char,int> mp;

        int l = -1, ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(mp.count(s[i])){
                l = max(l , mp[s[i]]);
            }
            mp[s[i]] = i;
            ans = max(ans, i-l);
        }

        return ans;
    }
};