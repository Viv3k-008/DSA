class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        pair<int,int> maxi = {0,0};

        for(int i = 0 ; i < n ; i++){
            // expand for even
            int u = i , v = i+1;
            while(u >= 0 && v < n && s[u] == s[v]) u-- , v++;

            if(v-u-1 > maxi.second-maxi.first+1){
                maxi.first = u+1;
                maxi.second = v-1;
            }

            // expand for odd
            u = i , v = i;
            while(u >= 0 && v < n && s[u] == s[v]) u-- , v++;

            if(v-u-1 > maxi.second-maxi.first+1){
                maxi.first = u+1;
                maxi.second = v-1;
            }
        }

        return s.substr(maxi.first , maxi.second-maxi.first+1);
    }
};