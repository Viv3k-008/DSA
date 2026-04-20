class Solution {
public:
    unordered_map<int, vector<string>> dp;

    vector<string> solve(int i, string &s, unordered_set<string> &st) {
       
       if(dp.count(i)){
        return dp[i];
       }

       vector<string> res;
       if(i == s.size()){
          res.push_back("");
          return res;
       }

       string temp = "";
       for(int k = i ; k < s.size() ; k++){
          temp += s[k];

          if(st.count(temp)){
            vector<string> next = solve(k+1 , s , st);

            for(string x : next){
                if(x == ""){
                    res.push_back(temp);
                }
                else res.push_back(temp + " " + x);
            }
          }
       }

        return dp[i] = res;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        return solve(0, s, st);
    }
};