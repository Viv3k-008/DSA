class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();

        unordered_map<int,int> mp , mp2;
        vector<int> ans;

        for(int i = 0 ; i < n ; i++){
            mp[nums2[i]]++;
        }

        for(int i = 0 ; i < nums1.size() ; i++){
            if(mp.count(nums1[i]) && !mp2.count(nums1[i])){
                ans.push_back(nums1[i]);
                mp2[nums1[i]]++;
            }
        }

        return ans;
    }
};