class Solution {
public:
    int fn(int i , vector<int>& nums , vector<int>& dp){
        if(i == nums.size()-1){
            return 0;
        }

        if(dp[i] != -1) return dp[i];

        int cur = 1e9;
        for(int k = 1 ; k <= nums[i] ; k++){

            if(i+k >= nums.size()) continue;

            int temp = 1 + fn(i+k , nums , dp);

            cur = min(temp , cur);
        }

        return dp[i] = cur;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , -1);
        return fn(0 , nums , dp);
    }
};