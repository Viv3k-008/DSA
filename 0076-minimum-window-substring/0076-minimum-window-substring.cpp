class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size() , required = t.size() , formed = 0 , left = 0;

        unordered_map<char,int> window , need;

        for(char c : t) need[c]++;

        int stIdx = -1 , minLen = INT_MAX;

        for(int i = 0 ; i < n ; i++){

            char ch = s[i];

            window[ch]++;

            if(need[ch] > 0 && window[ch] <= need[ch]){
                formed++;
            }

            while(formed == required){
                char c = s[left];

                window[c]--;

                if(i-left+1 < minLen){
                    minLen = i-left+1;
                    stIdx = left;
                }

                if(need[c] > 0 && window[c] < need[c]){
                    formed--;
                }

                left++;
            }
        }

        if(stIdx == -1) return "";

        return s.substr(stIdx , minLen);
    }
};