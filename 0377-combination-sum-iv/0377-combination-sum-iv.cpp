class Solution {
public:
    vector<int> dp;
    int fn(int n, vector<int>& nums, int target){
        if(target == 0) return 1;
        if(target < 0) return 0;
        
        if(dp[target] != -1) return dp[target];

        int op = 0;
        for(int k = 0; k < n ; k++){
            if(target >= nums[k]){
                op += fn(n, nums, target-nums[k]);
            }
        }


        return dp[target] = op;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();

        dp.resize(target+1, -1);
        return fn(n, nums, target);
    }
};