class Solution {
public:
    // int fn(int i , vector<int>& nums , vector<int>& dp){
    //     if(i >= nums.size()){
    //         return 0;
    //     }
    //     if(dp[i] != -1) return dp[i];

    //     int op1 = fn(i+2 , nums , dp) + nums[i];
    //     int op2 = fn(i+1 , nums , dp);

    //     return dp[i] = max(op1 , op2);
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();

        int next = 0 , secNext = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            int cur = max(secNext+nums[i] , next);

            secNext = next;
            next = cur;
        }

        return next;
    }
};