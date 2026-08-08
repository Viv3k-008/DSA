class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();

        sort(tokens.begin(), tokens.end());
        
        int i = 0, j = n-1, s = 0, p = power, ans = 0;
        while(i <= j){
            if(p >= tokens[i]){
                p -= tokens[i];
                s++;
                i++;
            }
            else {
                if(s == 0) return 0;
                s--;
                p += tokens[j];
                j--;
            }
            ans = max(s, ans);
        }

        return ans;
    }
};