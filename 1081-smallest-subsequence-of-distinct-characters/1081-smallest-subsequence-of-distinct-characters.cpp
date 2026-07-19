class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();

        unordered_map<char,int> mp , mp2;
        stack<char> stk;
        for(char c : s) mp[c]++;

        int len = mp.size();

        for(char c : s){
            mp[c]--;
            if(mp[c] == 0){
                mp.erase(c);
            }
            if(mp2.count(c)) continue;
            while(!stk.empty() && stk.top() > c && mp.count(stk.top())){
                mp2[stk.top()]--;
                if(mp2[stk.top()] == 0){
                    mp2.erase(stk.top());
                }
                stk.pop();
            }

            mp2[c]++;
            stk.push(c);
        }

        string ans = "";
        while(!stk.empty()){
            char c = stk.top();
            ans += c;
            stk.pop();
        }

        reverse(ans.begin(),ans.end());


        return ans;
        
    }
};