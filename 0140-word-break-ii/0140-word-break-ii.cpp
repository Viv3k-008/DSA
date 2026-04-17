class Solution {
public:
    vector<string> ans;
    void fn(int i , string &s , vector<string>& wordDict , string temp , string store , unordered_map<string,int>& mp){
        if(i == s.size()){
            if(mp.count(temp)){
                if(store.size() == 0) store = temp;
                else store = store + " " + temp;
                ans.push_back(store);
            }
            return;
        }

        // op1 
        if(mp.count(temp)){
            string newStore;
            if(store.size() == 0) newStore = temp;
            else newStore = store + " " + temp;

            fn(i, s, wordDict, "", newStore, mp);
        }

        // op2
        fn(i+1 , s , wordDict , temp+s[i] , store , mp);
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        unordered_map<string,int> mp;

        for(int i = 0 ; i < n ; i++){
            mp[wordDict[i]]++;
        }

        fn(0 , s , wordDict , "" , "" , mp);

        return ans;
    }
};