class Solution {
public:
    vector<vector<int>> dp;
    int fn(int i, int n, int curSum, int target, vector<int>& nums){
        if(i == n || curSum == target){
            return curSum;
        }

        if(dp[i][curSum] != -1) return dp[i][curSum];

        int op1 = -1e9;
        if((curSum + nums[i]) <= target){
            op1 = fn(i+1, n, curSum+nums[i], target, nums);
        }

        int op2 = fn(i+1, n, curSum, target, nums);

        return dp[i][curSum] = max(op1, op2);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();

        int total = 0;
        for(int i : stones) total += i;

        dp.resize(n, vector<int>(total/2+1, -1));
        int sum = fn(0, n, 0, total/2, stones);

        return (total-sum) - sum;
    }
};