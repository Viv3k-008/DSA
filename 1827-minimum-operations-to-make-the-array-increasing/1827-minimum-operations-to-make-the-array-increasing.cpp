class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 0;

        int cost = 0, prev = nums[0];
        for(int i = 1; i < n ; i++){
            if(nums[i] <= prev){
                int inc = prev - nums[i] + 1;
                prev = nums[i] + inc;

                cost += inc;
            }
            else prev = nums[i];
        }

        return cost;
    }
};