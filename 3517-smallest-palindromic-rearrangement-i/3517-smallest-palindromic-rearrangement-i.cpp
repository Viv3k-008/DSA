class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if(n == 1) return s;

        vector<int> alphaLeft(26,0);

        for(int i = 0 ; i < n/2 ; i++){
            alphaLeft[s[i]-'a']++;
        }

        int idx = 0;
        for(int i = 0 ; i < 26 ; i++){
            if(alphaLeft[i] != 0){
                while(alphaLeft[i]--){
                    s[idx++] = i+'a';
                }
            }
        }


        if(n%2){
            s[idx++] = s[n/2];
        }

        for(int i = idx ; i < n ; i++){
            s[i] = s[n-i-1];
        }

        return s;
    }
};