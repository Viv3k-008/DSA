class Solution {
public:
    int partitionString(string s) {
        int n = s.size();

        vector<bool> mp(26,false);
        
        int ans = 1;
        for(char c : s){
            if(mp[c-'a']){
                mp.assign(26,false);
                cout<<c<<" ";
                ans++;
            }

            mp[c-'a'] = true;
        }
        return ans;
    }
};