class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n), suffix(n);
        for(int i = 0; i < n ; i++){
            prefix[i] = (i == 0)? nums[i] : nums[i]*prefix[i-1];
        }
        for(int i = n-1; i >= 0; i--){
            suffix[i] = (i == n-1)? nums[i] : nums[i]*suffix[i+1];
        }

        vector<int> ans;
        for(int i = 0; i < n ; i++){
            if(i == 0) ans.push_back(suffix[i+1]);
            else if(i == n-1) ans.push_back(prefix[i-1]);
            else {
                ans.push_back(prefix[i-1]*suffix[i+1]);
            }
        }

        return ans;
    }
};