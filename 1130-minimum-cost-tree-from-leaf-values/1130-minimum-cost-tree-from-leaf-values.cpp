class Solution {
public:
    vector<vector<int>> dp;
    int fn(int l, int r, vector<int>& nums, vector<vector<int>>& maxi){
        if(l >= r){
            return 0;
        }

        if(dp[l][r] != -1) return dp[l][r];

        int op = 1e9;
        for(int k = l; k < r; k++){
            op = min(op , maxi[l][k]*maxi[k+1][r] + fn(l, k, nums, maxi) + fn(k+1, r, nums, maxi));
        }

        return dp[l][r] = op;
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> maxi(n, vector<int>(n, 0));

        for(int i = 0 ; i < n ; i++){
            maxi[i][i] = arr[i];
            int maxiNum = arr[i];
            for(int j = i+1 ; j < n ; j++){
                maxiNum = max(maxiNum, arr[j]);
                maxi[i][j] = maxiNum;
            }
        }

        dp.resize(n, vector<int>(n, -1));
        return fn(0, n-1, arr, maxi);
    }
};