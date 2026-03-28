class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] != 1) continue;
            for(int j = i+1 ; j < n ; j++){
                if(nums[j] == 2){
                    ans = min(ans , abs(i-j));
                }
            }
            for(int j = i-1 ; j >= 0 ; j--){
                if(nums[j] == 2){
                    ans = min(ans , abs(i-j));
                }
            }
        }

        return ans == INT_MAX? -1 : ans;
    }
};