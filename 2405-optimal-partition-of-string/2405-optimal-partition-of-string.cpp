class Solution {
public:
    int partitionString(string s) {
        int n = s.size();

        unordered_map<char,int> mp;
        
        int ans = 1;
        for(char c : s){
            if(mp.count(c)){
                cout<<c<<" ";
                mp.clear();
                ans++;
            }

            mp[c]++;
        }
        return ans;
    }
};