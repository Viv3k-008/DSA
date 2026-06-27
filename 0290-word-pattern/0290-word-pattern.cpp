class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size();
        stringstream ss(s);
        vector<string> str;

        string word;
        while(ss >> word){
            str.push_back(word);
        }
        if(str.size() != n) return false;

        unordered_map<char,string> mp;
        unordered_map<string,bool> check;
        for(int i = 0 ; i < n ; i++){
            if(!mp.count(pattern[i]) && !check[str[i]]){
                mp[pattern[i]] = str[i];
                check[str[i]] = true;
            }
            if(!mp.count(pattern[i]) && check[str[i]]){
                return false;
            }
            else{
                if(str[i] != mp[pattern[i]]){
                    return false;
                }
            }
        }

        return true;
    }
};