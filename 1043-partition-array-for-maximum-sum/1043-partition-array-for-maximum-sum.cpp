class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> dp(n+1, 0);

        for(int i = n-1; i >= 0 ; i--){
            int cost = INT_MIN, maxi = INT_MIN;

            for(int j = i ; j < n && j < i+k ; j++){
                maxi = max(arr[j], maxi);

                cost = max(maxi*(j-i+1)+dp[j+1] , cost);
            }

            dp[i] = cost;
        }

        return dp[0];
    }
};