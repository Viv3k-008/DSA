class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        sort(nums1.begin(), nums1.end());

        if(nums1[0]%2) return true;

        for(int i : nums1){
            if(i%2) return false;
        }

        return true;
    }
};