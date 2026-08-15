class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 0);

        for(int i = n-2; i >= 0; i--){
            int op = 1e9;
            for(int j = i+1; j <= min(n-1, i+nums[i]) ; j++){
                op = min(op, 1+dp[j]);
            }
            dp[i] = op;
        }

        return dp[0];
    }
};