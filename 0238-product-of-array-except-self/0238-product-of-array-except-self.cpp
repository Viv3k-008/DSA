class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> suffix(n);
        for(int i = n-1; i >= 0; i--){
            suffix[i] = (i == n-1)? nums[i] : nums[i]*suffix[i+1];
        }

        int prefix = 1;
        for(int i = 0; i < n ; i++){
            if(i == 0) suffix[i] = suffix[i+1];
            else if(i == n-1) suffix[i] = prefix;
            else {
                suffix[i] = prefix*suffix[i+1];
            }

            prefix *= nums[i];
        }

        return suffix;
    }
};