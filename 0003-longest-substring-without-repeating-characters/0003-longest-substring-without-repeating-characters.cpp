class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        unordered_map<char,int> mp;

        int l = 0 , ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(mp.count(s[i])){
                if(mp[s[i]] >= l) l = mp[s[i]]+1;
            }

            ans = max(ans , i-l+1);
            mp[s[i]] = i;
        }

        return ans;
    }
};