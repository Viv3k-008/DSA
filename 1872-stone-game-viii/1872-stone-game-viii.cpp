class Solution {
public:
    vector<int> prefix;
    vector<int> dp;
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        prefix.resize(n);
        dp.resize(n+1, 0);
       

        for(int i = 0 ; i < n ; i++){
            prefix[i] = (i == 0)? stones[i] : prefix[i-1]+stones[i];
        }
        
        dp[n-1] = prefix[n-1];
        for(int i = n-2; i >= 1; i--){
            dp[i] = max(prefix[i]-dp[i+1], dp[i+1]);
        }


        return dp[1];
    }
};