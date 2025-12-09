class Solution {
public:
    int fn(int i , vector<int>& nums , vector<int>& dp){
        if(i >= nums.size()){
            return 0;
        }
        if(dp[i] != -1) return dp[i];

        int op1 = fn(i+2 , nums , dp) + nums[i];
        int op2 = fn(i+1 , nums , dp);

        return dp[i] = max(op1 , op2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        vector<int> nums1(nums.begin(),nums.end()-1);
        vector<int> nums2(nums.begin()+1 , nums.end());

        vector<int> dp1(n , -1);
        vector<int> dp2(n , -1);
        int ans1 = fn(0 , nums1 , dp1);
        int ans2 = fn(0 , nums2 , dp2);

        return max(ans1 , ans2);
    }
};