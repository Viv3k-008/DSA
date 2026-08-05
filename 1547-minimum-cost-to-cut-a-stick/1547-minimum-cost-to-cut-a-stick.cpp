class Solution {
public:
    vector<vector<int>> dp;
    int fn(int i, int r, int len, vector<int>& nums){
        if((r - i) == 1) return 0;
        if(i >= r) return 1e9;

        if(dp[i][r] != -1) return dp[i][r];

        int mini = 1e9;
        for(int k = i+1; k < r; k++){
            int cost = len + fn(i, k, nums[k]-nums[i], nums) + fn(k, r, nums[r]-nums[k], nums);

            mini = min(mini, cost);
        }

        return dp[i][r] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int len = cuts.size();
        sort(cuts.begin(), cuts.end());

        vector<int> nums(len+2, 0);

        for(int i = 0 ; i < len+2 ; i++){
            if(i == 0) continue;
            else if(i == len+1) nums[i] = n;
            else nums[i] = cuts[i-1];
        }

        dp.resize(len+2, vector<int>(len+2, -1));

    

        return fn(0, len+1, n, nums);
    }
};