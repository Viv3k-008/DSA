class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0, ans = 0;
        long long prod = 1;

        for(int i = 0; i < n ; i++){
            prod *= nums[i];

            while(prod >= k && l <= i){
                prod /= 1LL*nums[l++];
            }

            ans += i-l+1;
        }

        return ans;
    }
};