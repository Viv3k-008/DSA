class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size() , sum = 0;

        for(int i : nums) sum += i;

        return sum%k;
    }
};