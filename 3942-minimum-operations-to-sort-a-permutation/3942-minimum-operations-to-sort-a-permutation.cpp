class Solution {
public:
    bool isIncreasing(int minIdx, int n, vector<int>& nums) {
        int i;
        for (i = minIdx; i < (minIdx + n-1); i++) {
            if (nums[(i + 1) % n] - 1 != nums[i % n]) {
                return false;
            }
        }

        if ((i+1)%n == minIdx)
            return true;
        else
            return false;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int minIdx = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                minIdx = i;
                break;
            }
        }

        bool increasing = isIncreasing(minIdx, n, nums), decreasing = false;

        if (!increasing) {
            reverse(nums.begin(), nums.end());
            minIdx = n - minIdx - 1;
            decreasing = isIncreasing(minIdx, n, nums);
        }

        if (!increasing && !decreasing) {
            return -1;
        }

        int ans = n;
        if (increasing) {
            ans = min(minIdx, 2 + n - minIdx);
        } else
            ans = min(1 + n - minIdx, 1 + minIdx);

        return ans;
    }
};
