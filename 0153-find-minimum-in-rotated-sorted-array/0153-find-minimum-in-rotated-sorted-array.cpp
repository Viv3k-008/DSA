class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        int l = 0 , r = n-1 , mini = INT_MAX;

        while(l <= r){
            int mid = l+(r-l)/2;

            if(nums[l] <= nums[mid]){
                mini = min(mini , nums[l]);
                l = mid+1;
            }
            else {
                mini = min(mini , nums[mid]);
                r = mid-1;
            }
           
        }

        return mini;
    }
};