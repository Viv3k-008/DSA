class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = word.size();

        unordered_map<string,bool> mp;
        for(int i = 0 ; i < n ; i++){
            string s = "";
            for(int j = i ; j < n ; j++){
                s += word[j];
                mp[s] = true;
            }
        }

        int cnt = 0;
        for(int i = 0 ; i < patterns.size() ; i++){
            string str = patterns[i];
            if(mp.count(str)){
                cnt++;
            }
        }

        return cnt;
    }
};