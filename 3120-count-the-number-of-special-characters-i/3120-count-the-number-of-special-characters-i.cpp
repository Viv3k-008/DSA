class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();

        unordered_map<char,int> mp , flag;

        for(int i = 0 ; i < n ; i++){
            mp[word[i]]++;
        }

        int cnt = 0;
        for(pair<char,int> it : mp){
            if(it.first >= 97){
                if(mp.count(it.first-32) && !flag.count(it.first)){
                    cnt++;
                    flag[it.first]++;
                }
            }
        }

        return cnt;
    }
};