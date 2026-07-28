class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if(n == 1) return s;

        vector<int> alphaLeft(26,0);

        for(int i = 0 ; i < n/2 ; i++){
            alphaLeft[s[i]-'a']++;
        }

        string ans = "";

        for(int i = 0 ; i < 26 ; i++){
            if(alphaLeft[i] != 0){
                while(alphaLeft[i]--){
                    ans += i+'a';
                }
            }
        }

        string temp = ans;
        reverse(temp.begin(),temp.end());

        if(n%2){
            ans += s[n/2];
        }

        ans += temp;

        return ans;
    }
};