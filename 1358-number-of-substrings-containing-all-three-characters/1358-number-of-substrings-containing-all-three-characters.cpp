class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        int l = 0 , ans = 0;
        unordered_map<char,int> mp;
        for(int r = 0 ; r < n ; r++){
            int rightCnt = 0 , leftCnt = 0;
            mp[s[r]]++;
            if(mp['a']&&mp['b']&&mp['c']){
                rightCnt = n-r;

                while(mp['a']&&mp['b']&&mp['c']){
                    leftCnt++;
                    mp[s[l]]--;
                    if(mp[s[l]] == 0) mp.erase(s[l]);
                    l++;
                }
                cout<<leftCnt<<" "<<rightCnt<<" "<<leftCnt*rightCnt<<endl;
            }

            ans += leftCnt*rightCnt;
        }

        return ans;
    }
};