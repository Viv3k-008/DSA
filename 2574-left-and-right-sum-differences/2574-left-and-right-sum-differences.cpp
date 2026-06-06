class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return vector<int>{0};
        vector<int> preffixSum(n) , suffixSum(n) , ans(n);

        for(int i = 0 ; i < n ; i++){
            preffixSum[i] = (i == 0)? nums[i] : nums[i]+preffixSum[i-1];
            suffixSum[n-1-i] = (i == 0)? nums[n-1-i] : nums[n-1-i]+suffixSum[n-1-i+1];
        }

        for(int i = 0 ; i < n ; i++){
            int preIdx = i-1 , sufIdx = i+1;
            if(preIdx < 0) ans[i] = suffixSum[sufIdx];
            else if(sufIdx > n-1) ans[i] = preffixSum[preIdx];
            else{
                ans[i] = abs(preffixSum[preIdx] - suffixSum[sufIdx]);
            }
        }

        return ans;

    }
};