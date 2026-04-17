class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        unordered_map<char,int> mp;

        int l = 0 , maxi = 0;
        for(int r = 0 ; r < n ; r++){
            if(mp.count(s[r])){
                if(mp[s[r]] >= l) l = mp[s[r]]+1;
            }

            maxi = max(maxi , r-l+1);
            mp[s[r]] = r;
        }

        return maxi;
    }
};