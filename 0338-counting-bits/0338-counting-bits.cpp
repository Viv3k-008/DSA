class Solution {
public:
    int fn(int n){
        int cnt = 0;

        while(n){
            if(n%2){
                cnt++;
            }
            n /= 2;
        }

        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> ans;

        for(int i = 0 ; i <= n ; i++){
            int cnt = fn(i);
            ans.push_back(cnt);
        }

        return ans;
    }
};