class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0;
        int n = s.size();

        for(int i = 0 ; i < t.size() ; i++){
            if(s[idx] == t[i]){
                idx++;
                continue;
            }
        }

        return idx == s.size();
    }
};