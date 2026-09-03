class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        int smallest = 1e9;
        for(int i : nums1) smallest = min(smallest, i);

        if(smallest%2) return true;
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