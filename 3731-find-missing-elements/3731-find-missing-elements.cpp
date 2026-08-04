class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();

        int mini = INT_MAX, maxi = INT_MIN;
        unordered_map<int,int> mp;
        for(int i : nums){
            mini = min(mini, i);
            maxi = max(maxi, i);
            mp[i]++;
        }

        vector<int> ans;
        while(mini <= maxi){
            if(!mp.count(mini)){
               ans.push_back(mini);
            }

            mini++;
        }

        return ans;
    }
};