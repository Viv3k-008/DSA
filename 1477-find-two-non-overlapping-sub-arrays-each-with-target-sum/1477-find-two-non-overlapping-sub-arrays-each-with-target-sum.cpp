class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        int l = 0, sum = 0, ans = 1e9;

        vector<int> dp(n, 1e9);
        for(int i = 0 ; i < n ; i++){
            sum += arr[i];

            while(sum > target && l <= i){
                sum -= arr[l++];
            }

            int prev = i-1 < 0? 1e9 : dp[i-1];
            if(sum == target){
                if(l-1 >= 0) ans = min(dp[l-1]+i-l+1, ans);
                dp[i] = min(prev, i-l+1);
            }
            else dp[i] = prev;
        }

        return ans == 1e9? -1 : ans;
    }
};