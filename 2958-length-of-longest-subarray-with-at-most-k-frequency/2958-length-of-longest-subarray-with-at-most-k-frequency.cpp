class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, len = 0, left = 0;

        unordered_map<int,int> mp;
        for(int i = 0 ; i < n; i++){
            mp[nums[i]]++;

            if(mp.count(nums[i]) && (mp[nums[i]] > k)){
                while(mp[nums[i]] > k){
                    mp[nums[left++]]--;
                }
            }

            ans = max(i-left+1, ans);
        }

        return ans;
    }
};