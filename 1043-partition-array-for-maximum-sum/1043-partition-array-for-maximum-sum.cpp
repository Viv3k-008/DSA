class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> dp(n+1, 0);

        for(int i = n-1; i >= 0 ; i--){
            int maxi = INT_MIN , cost = INT_MIN;
            for(int j = i ; j < i+k && j < n; j++){
                maxi = max(arr[j], maxi);

                cost = max((j-i+1)*maxi + dp[j+1] , cost);
            }

            dp[i] = cost;
        }

        return dp[0];
    }
};