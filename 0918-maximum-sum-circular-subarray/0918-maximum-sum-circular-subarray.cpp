class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int total = 0, maxSum = INT_MIN, curSum = 0, minSum = INT_MAX, curMin = 0;

        for(int i : nums){
            curSum = max(curSum+i, i);
            maxSum = max(maxSum, curSum);

            total += i;

            curMin = min(curMin+i, i);
            minSum = min(minSum, curMin);
        }

        return maxSum > 0 ? max(maxSum, total-minSum) : maxSum; 
    }
};
/*
 For more understanding refer this solution
 https://leetcode.com/problems/maximum-sum-circular-subarray/solutions/178422/one-pass-by-lee215-navi
*/