class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> suffix(n);

        for(int i = n-1; i >= 0 ; i--){
            suffix[i] = (i == n-1)? nums[i] : min(nums[i],suffix[i+1]);
        }

        int maxi = -1e9, ans = n;
        for(int i = 0 ; i < n ; i++){
            maxi = max(maxi, nums[i]);
            if((maxi - suffix[i]) <= k){
                ans = min(i, ans);
            }
        }

        return ans == n? -1 : ans;
    }
};