class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> mp;

        for(int i : nums){
            if(mp.count(i)) return true;
            mp[i]++;
        }

        return false;
    }
};