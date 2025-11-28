class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> prefix(k , LLONG_MAX);
        prefix[0] = 0;

        long long sum = 0 , ans = LLONG_MIN;

        for(int i = 0 ; i < n ; i++){
            int rem = (i+1)%k;
            sum += nums[i];

            if(prefix[rem] != LLONG_MAX){
                ans = max(ans , sum-prefix[rem]);
            }
            prefix[rem] = min(prefix[rem] , sum);
        }

        return ans;
    }
};