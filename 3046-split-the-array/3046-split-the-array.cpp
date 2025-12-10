class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int n = nums.size();

        if(n%2) return false;

        unordered_map<int,int> mp;
        for(int i : nums) mp[i]++;

        for(auto it : mp) if(it.second>2) return false;

        return true;
    }
};