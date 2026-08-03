class Solution {
public:
    vector<int> dp;
    int fn(int i, int n, vector<int>& nums){
        if(i >= n){
            return 0;
        }

        if(dp[i] != -1) return dp[i];

        int maxi = INT_MIN;
        int sum = 0;
        for(int k = i; k < i+3 && k < n ; k++){
            sum += nums[k];
            maxi = max(sum-fn(k+1, n, nums), maxi);
        }

        return dp[i] = maxi;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        dp.resize(n, -1);
        int Alice = fn(0, n, stoneValue);

        if(Alice > 0){
            return "Alice";
        }
        else if(Alice < 0){
            return "Bob";
        }
        else return "Tie";
    }
};