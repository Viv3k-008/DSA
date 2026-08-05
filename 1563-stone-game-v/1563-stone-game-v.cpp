class Solution {
public:
    vector<int> prefix;
    vector<vector<int>> dp;
    int fn(int l, int r, vector<int>& nums){
        if(l == r) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        int cur = INT_MIN;
        for(int k = l; k < r; k++){
            int suml = (l == 0)? prefix[k] : prefix[k]-prefix[l-1];
            int sumr = prefix[r]-prefix[k];

            int op = 0;
            if(suml > sumr){
                op = sumr + fn(k+1, r, nums);
            }
            else if(suml < sumr){
                op = suml + fn(l, k, nums);
            }
            else op = max(suml + fn(l, k, nums), sumr + fn(k+1, r, nums));

            cur = max(cur, op);
        }

        return dp[l][r] = cur;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        prefix.resize(n, 0);

        for(int i = 0 ; i < n ; i++){
            prefix[i] = (i == 0)? stoneValue[i] : stoneValue[i] + prefix[i-1];
        }

        dp.resize(n, vector<int>(n, -1));
        return fn(0, n-1, stoneValue);
    }
};