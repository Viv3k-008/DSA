class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        int alphaCnt = 0, ans = 0, add = 1;

        vector<int> alpha(26, 0);

        for(int i = 0 ; i < n ; i++){
            alpha[word[i]-'a']++;
        }

        sort(alpha.rbegin(),alpha.rend());

        for(int i : alpha){
            if(i > 0){
                alphaCnt++;

                ans += i*add;

                if(alphaCnt%8 == 0) add++;
            }
        }

        return ans;
    }
};