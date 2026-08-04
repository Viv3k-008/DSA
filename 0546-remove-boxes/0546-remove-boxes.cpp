class Solution {
public:
    vector<vector<vector<int>>> dp;
    int fn(int l, int r, int x, vector<int>& nums){
        if(l == r){
            return (x+1)*(x+1);
        }
        if(l > r) return 0;

        if(dp[l][r][x] != -1) return dp[l][r][x];

        int op1 = (x+1)*(x+1) + fn(l+1, r, 0, nums);

        int op2 = -1e9;
        for(int k = l+1; k <= r; k++){
            if(nums[k] == nums[l]){
                int temp = fn(l+1, k-1, 0, nums) + fn(k, r, x+1, nums);

                op2 = max(op2, temp);
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