class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int target = n-1;

        for(int i = n-1; i >= 0 ; i--){
            if(i == n-1) continue;

            int mini = min(target, i+nums[i]);

            if(mini >= target){
                target = i;
            }
        }

        return target == 0;
    }
};