class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> mp;

        for(char c : s) mp[c]++;

        int total = mp.size();

        int l = 0, len = INT_MIN;
        mp.clear();

        for(int r = 0 ; r < n ; r++){
            mp[s[r]]++;

            while(mp[s[r]] > 2){
                mp[s[l]]--;
                if(mp[s[l]] == 0){
                    mp.erase(s[l]);
                }
                l++;
            }
            len = max(len, r-l+1);
        }

        return len;
    }
};