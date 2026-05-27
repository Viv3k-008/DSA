class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();

        unordered_map<char,int> mp , flag;

        for(int i = 0 ; i < n ; i++){
           if(word[i] >= 97) mp[word[i]] = i;
           else if(!mp.count(word[i])) mp[word[i]] = i;
        }

        int cnt = 0;
        for(pair<char,int> it : mp){
            if(it.first >= 97){
                if(mp.count(it.first-32) && !flag.count(it.first) && mp[it.first-32] > mp[it.first]){
                    cnt++;
                    flag[it.first]++;
                }
            }
        }

        return cnt;
    }
};