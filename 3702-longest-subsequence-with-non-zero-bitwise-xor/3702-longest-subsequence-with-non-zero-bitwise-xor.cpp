class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int xr = 0, zeroCnt = 0;

        for(int i : nums){
            if(i == 0) zeroCnt++;
            xr ^= i;
        }

        if(xr != 0) return n;
        return (zeroCnt == n)? 0 : n-1;
    }
};