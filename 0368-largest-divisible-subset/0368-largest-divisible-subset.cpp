class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> parent(n, -1);
        int size = 0, last = -1;

        vector<int> dp(n, 1);
        for(int i = 0 ; i < n ; i++){
            for(int j = i-1; j >= 0 ; j--){
                if((nums[i]%nums[j] == 0) && (dp[j]+1 > dp[i])){
                    parent[i] = j;
                    dp[i] = dp[j]+1;
                }
            }
            if(dp[i] > size){
                size = dp[i];
                last = i;
            }
        }


        vector<int> ans;
        int idx = last;
        while(idx != -1){
            ans.push_back(nums[idx]);
            idx = parent[idx];
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};