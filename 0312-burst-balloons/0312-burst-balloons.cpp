class Solution {
public:
    vector<vector<int>> dp;
    int fn(int l, int r, vector<int>& nums){
        if(l >= r-1) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        int cost = -1e9;
        for(int k = l+1 ; k < r ; k++){
            int cur = nums[l]*nums[k]*nums[r];

            cost = max(cur+fn(l, k, nums)+fn(k, r, nums) , cost);
        }

        return dp[l][r] = cost;
    }
    int maxCoins(vector<int>& arr) {
        int n = arr.size();

        vector<int> nums(n+2);
        nums[0] = 1, nums[n+1] = 1;

        for(int i = 1 ; i < n+1 ; i++){
            nums[i] = arr[i-1];
        }

        dp.resize(n+2, vector<int>(n+2, -1));
        return fn(0, n+1, nums);
        
    }
};