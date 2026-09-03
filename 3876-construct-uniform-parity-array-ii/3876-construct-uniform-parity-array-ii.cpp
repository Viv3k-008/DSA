class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        sort(nums1.begin(), nums1.end());

        if(nums1[0]%2) return true;
        // both even or odd can be converted to different parity by substracting with odd.
        // if smallest number is odd then we can convert every number to odd.

        for(int i : nums1){
            if(i%2) return false;
        }
        // if the smallest is even, so every even can't be converted to odd and if their are some odd so that also will not be converted to odd.
        // answer can be true if and only if their are only even  if the smallest element is even.

        return true;
    }
};