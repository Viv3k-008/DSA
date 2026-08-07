class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();

        long long ans = nums[0], sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            if(i == 0){
                ans = max(ans, 1LL*nums[i]);
                continue;
            }
            else {
                int avg = ceil((double)sum/(i+1));
                ans = max(ans, 1LL*avg);
            }
        }

        return (int)ans;
    }
};