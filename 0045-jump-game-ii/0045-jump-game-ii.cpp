class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        if(n <= 1) return 0;

        int maxRange = 0 , curEnd = 0 , jumps = 0;

        for(int i = 0 ; i < n ; i++){
            maxRange = max(maxRange , i+nums[i]);

            if(i == curEnd){
                jumps++;
                curEnd = maxRange;
            }

            if(curEnd >= n-1) break;
        }

        return jumps;
    }
};