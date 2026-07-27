class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();

        int l = k , r = k;
        int minVal = nums[k] , ans = minVal;

        while(l > 0 || r < n-1){
            int left = (l == 0)? -1 : nums[l-1];
            int right = (r == n-1)? -1 : nums[r+1];

            if (left > right) {
                l--;
                minVal = min(minVal, nums[l]);
            } else {
                r++;
                minVal = min(minVal, nums[r]);
            }
            ans = max(ans, (r - l + 1) * minVal);
        }

        return ans;
    }
};