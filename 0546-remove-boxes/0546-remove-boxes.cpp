class Solution {
public:
    vector<vector<vector<int>>> dp;
    int fn(int l, int r, int x, vector<int>& nums){
        if(l > r) return 0;
        if(l == r) return (x+1)*(x+1);

        if(dp[l][r][x] != -1) return dp[l][r][x];

        int op1 = (x+1)*(x+1) + fn(l+1, r, 0, nums);
        int op2 = INT_MIN;
        for(int k = l+1; k <= r; k++){
            if(nums[l] == nums[k]){
                op2 = max(op2, fn(l+1, k-1, 0, nums)+fn(k, r, x+1, nums));
            }
        }

        return dp[l][r][x] = max(op1, op2);
    }
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
    
        dp.resize(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return fn(0, n-1, 0, boxes);
    }
};